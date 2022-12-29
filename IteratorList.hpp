
#pragma once

#include <iostream>
#include "LinkedListSequence.hpp"
#include "LinkedList.hpp"




template<class T>

class IteratorList {



public:

    IteratorList(LinkedListSequence<T> list)  : elem(list.First()), item(0) {}
    IteratorList(LinkedListSequence<T> list, int ind) : elem(list.Next(ind - 1)) {
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

    Elem<T>* el () const override { return this->elem;}

    bool  operator!= (IteratorList<T> const& iter) override {
    return this->elem->val != iter.operator*();
    }



private:
    Elem<T>* const elem;
    int item;

};



