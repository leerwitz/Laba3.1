
#pragma once
#include <iostream>


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

}

template<typename T>
struct Elem {
    T val;
    Elem *next;

    Elem(const T &_val) : val(_val), next(nullptr) {};
};

template<class T>
        class Sort;

template<class T>
class LinkedList {
    
    friend class Sort<T>;
private:
    Elem<T> *first;
    Elem<T> *last;
    std:: size_t size;
public:
    LinkedList() noexcept : first(nullptr), last(nullptr), size(0) {};
    LinkedList(T* items,std:: size_t size1) noexcept :  size(size1){
        Elem<T>* p = new Elem(items[0]);
        p->val = items[0];
        this->first = p;
        this->last = p;

        for (int i = 1; i < size1; ++i) {
            Elem<T>* p = new Elem(items[i]);
            this->last->next = p;
            this->last = p;
            if (this->first->next == nullptr) this->first->next = this->last;

        }
    }
    LinkedList(LinkedList<T>* list , std:: size_t size1 ) : first(nullptr), last(nullptr), size(0) {
        Elem<T>* p = list->first;
        for (int i = 0; i <size1 ; ++i) {
            this->Append(p->val);
            p = p->next;
        }
    };
    LinkedList(Elem<T>* first1, Elem<T>* last1) : first(nullptr), last(nullptr), size(0) {
        this->first = first1;
        this->last = last1;
        while (first1 != last1->next){
            ++this->size;
            first1 = first1->next;
    }
    }

    bool is_empty() {return first == nullptr; };

    void Append  (T& item) noexcept {
        Elem<T>* p = new Elem(item);
        if(is_empty()) {
            this->first = p;
            this->last = p;
        } else{
            this->last->next = p;
            this->last = p;
        }
        ++this->size;
    };

    void Prepend  (T& item) noexcept {
        Elem<T>* p = new Elem(item);
        if(is_empty()) {
            this->first = p;
            this->last = p;
        } else{
            p->next = this->first;
            this->first = p;
        }
        ++this->size;
    };

    T& GetFirst() const noexcept {return this->first->val;};
    T& GetLast() const noexcept {return this->last->val;};
    std:: size_t GetLength() const noexcept {return this->size;};
    T&  Get(std:: size_t index) const noexcept {
        Elem<T>* p = this->first;
        for (int i = 1; i <index ; ++i) {
            p = p->next;
        }
        return p->val;
    };

    LinkedList<T>* GetSubList(std::size_t startIndex, std::size_t endIndex) const noexcept{
        Elem<T>* p = this->first;
        std::size_t n = endIndex - startIndex + 1;
        T* data = new T[n];
        for (std::size_t i = 1; i < startIndex; ++i) {p = p->next;}
        for (std::size_t j = 0; j < n ; ++j) {
            data[j] = p->val;
            p = p->next;
        }
        auto new_list = new LinkedList<T>(data,n);
        return  new_list;
    };

    void InsertAt(T& item, std:: size_t index) noexcept {
        Elem<T>* prev = this->first;
        for (int i = 1; i < index - 1; ++i) {prev = prev->next;}
        Elem<T>* p = new Elem(item);
        p->next = prev->next;
        prev->next = p;
        ++size;
    };

    LinkedList<T>* Concat(LinkedList<T>* list)  {
        auto new_list = new LinkedList<T>(this, this->size);
        Elem<T>* p = list->first;
        std::size_t size1 = list->GetLength();
        for (int i = 0; i < size1; ++i) {
            new_list->Append(p->val);
            p = p->next;
        }
        return new_list;
    };

    void del (std::size_t n) noexcept {
        Elem<T>* p = first;
        for(int i=1;i<n-1;i++)
            p=p->next;
        Elem<T>* q = p->next;
        p->next=q->next;
        q->next= nullptr;
        delete q;
        --this->size;
    }

    Elem<T>* LinkNext(std::size_t ind) noexcept {
        Elem<T>* p = this->first;
        for (int i = 0; i <= ind; ++i) {
            p = p->next;
        }
        return p;
    }

    Elem<T>* LinkFirst() noexcept {
        return this->first;
    }

    Elem<T>* LinkLast() noexcept {
        return this->last;
    }

// СОРТИРОВКИ

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

    static Elem<T>* MergeList(Elem<T>* list1,Elem<T>* list2, Elem<T>* newList ){
        if (list1 == nullptr)
            return list2;

        if (list2 == nullptr)
            return list1;




        if (cmp(list1->val, list2->val)){
            newList = list2;
            MergeList(list1, list2->next,newList->next);
        } else {
            newList = list1;
            MergeList(list1->next, list2,newList->next);
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
        Elem<T>* list1 ;
        Elem<T>* list2 ;
        divider(*first,&list1,&list2);
        MergeSort(&list1);
        MergeSort(&list2);
        Elem<T>* newList;
        *first = MergeList(list1,list2,newList);

    }



};

//ИТЕРАТОРЫ

template<class T>

struct IteratorList {



public:

    IteratorList(LinkedList<T> list)  : elem(list.First()), item(0) {}
    IteratorList(LinkedList<T> list, int ind) : elem(list.Next(ind - 1)) {
        item = ind;
    }

    IteratorList<T>& operator++() override {
        elem = elem->Next(item);
        ++item;
        return *this;
    }

    IteratorList<T>& operator--() override {
        elem = *elem->Prev(item);
        --item;
        return *this;
    }

    IteratorList<T>& operator-=(int displacement) override {
        for (int i = 0; i < displacement; ++i) {
            elem = *elem->Prev(item);
            --item;
        }
        return *this;
    }

    IteratorList<T>& operator+=(int displacement) override {
        for (int i = 0; i < displacement; ++i) {
            elem = elem->Next(item);
            ++item;
        }
        return *this;
    }

    T& operator*() const override {
        return elem->val;
    }

    bool operator== (IteratorList<T> const& iter) override {
        return this->elem->val == iter.operator*() ;
    }


    bool  operator!= (IteratorList<T> const& iter) override {
        return this->elem->val != iter.operator*();
    }

    T&  operator[] (const size_t& i){
        Elem<T>* current = this->elem;
        for (int j = 1; j < i ; ++j) {
            current = current->next;
        }
        return current->val;
    }


private:
    Elem<T>* const elem;
    int item;

};

