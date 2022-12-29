#pragma once

#include "iostream"
#include "Sequence.hpp"
#include "LinkedList.hpp"
#include <iomanip>
#include "DynamicArray.hpp"
/*
template<class T>
void SwapTmpNext(Elem<T>* tmp, Elem<T>* tail, Elem<T>* prev){
    prev->next = tmp->next;
    tmp->next = tail->next;
    tail->next = tmp;
}

template<class T>
bool cmp (const T& a, const T& b){
    return (a > b);
}

template<class T>
void Swap(T& elem1,T& elem2){
    T a;
    a = std::move(elem1);
    elem1 = std::move(elem2);
    elem2 = std::move(a);

}*/

template<class T>

class Sort {
/*
private:
    void SwapList(Elem<T>* current, Elem<T>* sequent, Elem<T>* prev){
        current->next = sequent->next;
        sequent->next = current;
        if (prev->next != nullptr)
            prev->next = sequent;
    }

    void InsertAfterPivot (Elem<T>* current, Elem<T>* piv, Elem<T>* prev){
        if (prev != nullptr)
            prev->next = current->next;
        current->next = piv->next;
        piv->next = current;
    }


    Elem<T>* first;
    Elem<T>* last;
public:
    Sort(LinkedList<T>* list) noexcept: first(list->first), last(list->last) {}


    static void BubbleSortList(Elem<T>* first, Elem<T>* last) {

        Elem<T> *current;

        bool fl = true;
        while (fl) {
            fl = false;
            current = first;
            while (current != last) {
                if (cmp(current->val, current->next->val)) {
                    Swap(current->val, current->next->val);
                    fl = true;
                }
                current = current->next;
            }
        }
    }


    static Elem<T>* QSortList(Elem<T>* first1, Elem<T>* last1){
        Elem<T>* pivot = first1;
        if (first1 == last1)
            return pivot;
        Elem<T>* tail = pivot;
        Elem<T>* tmp = pivot;
        Elem<T>* prev = pivot;
        while (tmp != last1){
            if (tmp->val < last1->val){
                pivot = tail;
                Swap(tmp->val, tail->val);
                tail = tail->next;
            }
            tmp = tmp->next;
        }
        Swap(tail->val,last1->val);

        return pivot;
    }

    static void QuickSort(Elem<T>* first, Elem<T>* last){
        Elem<T>* pivot = QSortList(first, last);
        if (pivot != first)
            QuickSort(first, pivot);
        if (pivot->next != last)
            QuickSort(pivot->next, last);
    }

    static Elem<T>* MergeList(Elem<T>* list1,Elem<T>* list2 ){
        if (list1 == nullptr)
            return list2;

        if (list2 == nullptr)
            return list1;
        Elem<T>* newList;

        if (cmp(list1->val, list2->val)){
            newList = list2;
            newList->next = MergeList(list1, list2->next);
        } else {
            newList = list1;
            newList->next = MergeList(list1->next, list2);
        }

        return newList;
    }

    static void divider(Elem<T>* list, Elem<T>** Right_piece, Elem<T>** Left_piece){
        if (list == nullptr || list->next == nullptr){
            *Right_piece = list;
            return;
        }
        Elem<T>* travel = list;
        Elem<T>* double_travel = list->next;
        while (double_travel != nullptr){
            double_travel = double_travel->next;
            if (double_travel != nullptr){
                travel = travel->next;
                double_travel = double_travel->next;
            }
        }
        *Left_piece = travel->next;
        travel->next = nullptr;
        *Right_piece = list;
    }

    static void MergeSort(Elem<T>** first) {
        if (*first == nullptr || (*first)->next == nullptr) {
            return;
        }
        Elem<T>* list1;
        Elem<T>* list2;
        divider(*first,&list1,&list2);
        MergeSort(&list1);
        MergeSort(&list2);
        *first = MergeList(list1,list2);
    }
};*/

public:
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


    static void merge_sort(DynamicArray<T>** vector, int first, int last) {
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
};