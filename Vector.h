#include <cstdlib>
#include <new>

template <typename T>
class Vector {
    private:
        size_t capacity{}, size{};
        T* data;

    public:
        Vector(size_t initialCapacity) 
            : capacity(initialCapacity), size(0) { data = static_cast<T*>(::operator new(sizeof(T) * capacity)); }

        ~Vector() {
            for (size_t i = 0; i < size; i++)
                data[i].~T();
            ::operator delete(data);
        }

        void push_back(const T& newElement) { new (&data[size++]) T(newElement); }

        T pop_back() {
            T lastElement = std::move(data[--size]);
            data[size].~T();
            return lastElement;
        }

        size_t get_size() const { return size; }

        T& operator[](size_t index) { return data[index]; }

        const T& operator[](size_t index) const { return data[index]; }
};