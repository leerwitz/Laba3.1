
#pragma once


#include <iostream>

template <class T>
class DynamicArray {
public:
    DynamicArray() noexcept : array(new T[10]), size(0), capacity(10) {}
    DynamicArray(int size) noexcept : array(new T[size]), size(size), capacity(size){}
    DynamicArray(T* items, std::size_t size1, std:: size_t capacity1 ) noexcept : array(new T[capacity1]), size(size1), capacity(capacity1){
        std::copy(items,items + capacity1, array);
    }
    ~DynamicArray() noexcept  {delete* array;}
public:
    T& get(std::size_t index)  const noexcept {return this->array[index] ;}
    std::size_t  getSize() const noexcept {return this->size;}
    void setSize(std::size_t size)  noexcept {this->size = size;}
    std::size_t getCapacity() const noexcept {return this->capacity;}
    void setCapacity (std::size_t capacity) noexcept { this->capacity = capacity;}
    void set(std:: size_t index, const T& value) noexcept {this->array[index] = value;}
    void resize (std::size_t newSize) {
        auto newArr = new DynamicArray<T>(newSize);
        for (std::size_t i = 0; i < this->size; ++i) {
            newArr->set(i, this->array[i]);
        }
        array = newArr->array;
        delete newArr->array;
    }
    T *link() noexcept {return this->array;}
    void DeleteArr(std:: size_t startIndex, std::size_t endIndex) noexcept {
        std:: size_t  n = endIndex - startIndex + 1;
        for (std::size_t i = startIndex; i < capacity - n; ++i ) { this->array[i] = this->array[i+n];}
        size -= n;
    }

    void Del( std::size_t Index) noexcept {
        for (std::size_t i = Index; i < capacity - 1 ; ++i ) { this->array[i] = this->array[i + 1];}
        --size;
    }

    static void copy_vec(const DynamicArray<T> &orig,const DynamicArray<T> &copy, int first, int first_copy) {
        int size_copy = copy.getSize();
        for (int i = 0; i < size_copy - first_copy; ++i) {
            copy[i + first_copy] = orig[first + i];
        }
    }


    static void merge(const DynamicArray<T> &vec1,const DynamicArray<T> &vec2, int size1, int size2, const DynamicArray<T>& vector) {
        int i = 0;
        int j = 0;

        while ((i < size1) && (j < size2)) {
            if (vec1[i] <= vec2[j]) {
                vector[i + j] = vec1[i];
                ++i;
            } else {
                vector[i + j] = vec2[j];
                ++j;
            }
        }
        if (j == size2) {
            copy_vec(vec1, vector, i, size1, j + i);
            //for (i; i < size1; ++i) { vector[i + j] = vec1[i]; }
        } else {
            copy_vec(vec2, vector, j, size2, i + j);
            //for (j; j < size2; ++j) { vector[i + j] = vec2[j]; }
        }

    }


    static void merge_sort(DynamicArray<T>* vector, int first, int last) {
        int mid = (last + first) / 2;
        int size1 = mid - first + 1;
        int size2 = last - first - size1 + 1;
        if (last - first > 0) {
            auto vec1 = new DynamicArray<T>();
            auto vec2 = new DynamicArray<T>();
            vec1->resize(size1);
            vec2->resize(size2);
            copy_vec(*vector, *vec1, 0,  0);
            copy_vec(*vector, *vec2, mid + 1 - first,  0);
            merge_sort(&vec1, first, mid);
            merge_sort(&vec2, mid + 1, last);
            merge(*vec1, *vec2, size1, size2, *vector);
            //delete vec1;
            //delete vec2;
        }

    }

private:
    T* array;
    std::size_t size;
    std::size_t  capacity;

};



