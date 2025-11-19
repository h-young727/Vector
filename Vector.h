#include <memory>
#include <cstddef>

template<typename T, typename Allocator = std::allocator<T>> 
class Vector {
        T* data_;
        size_t capacity_;
        size_t size_;
        Allocator alloc_;

    public:
        Vector()
            : data_(nullptr) 
            , capacity_(0)
            , size_(0)
            , alloc_() 
        {}

        Vector(size_t initial_capacity) 
            : data_(nullptr)
            , capacity_(initial_capacity)
            , size_(0)
            , alloc_()
        { 
            data_ = alloc_.allocate(initial_capacity);   
        }

        ~Vector() {
            for (size_t i = 0; i < size_; ++i) {
                std::destroy_at(&data_[i]);
            }

            if (data_) {
                alloc_.deallocate(data_, capacity_);
            }
        }

        T& operator[](size_t index) { 
            return data_[index]; 
        }

        const T& operator[](size_t index) const { 
            return data_[index]; 
        }

        void push_back(const T& new_element) { 
            if (size_ == capacity_) {
                size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
                T* new_data = alloc_.allocate(new_capacity);
                
                for (size_t i = 0; i < size_; ++i) {
                    std::construct_at(&new_data[i], std::move(data_[i]));
                    std::destroy_at(&data_[i]);
                }

                if (data_) {
                    alloc_.deallocate(data_, capacity_);
                }

                data_ = new_data;
                capacity_ = new_capacity;
            }

            std::construct_at(&data_[size_], new_element);
            ++size_;
        }

        void push_back(T&& new_element) {
            if (size_ == capacity_) {
                size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
                T* new_data = alloc_.allocate(new_capacity);

                for (size_t i = 0; i < size_; ++i) {
                    std::construct_at(&new_data[i], std::move(data_[i]));
                    std::destroy_at(&data_[i]);
                }

                if (data_) alloc_.deallocate(data_, capacity_);

                data_ = new_data;
                capacity_ = new_capacity;
            }

            std::construct_at(&data_[size_], std::move(new_element));
            ++size_;
        }

        size_t capacity() const {
            return capacity_;
        }

        size_t size() const {
            return size_;
        }
};