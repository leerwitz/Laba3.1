#include <iostream>
#include "DynamicArray.hpp"
#include "LinkedList.hpp"
#include <vector>
#include "VectorSorter.hpp"
#include "libs.hpp"
int main() {

    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    high_resolution_clock::time_point t_start, t_end;
    duration<double> time_span1, time_span2, time_span3, time_span4, time_span5, time_span6, time_span7, time_span8, time_span9;
    int n = 22;

    fstream file_for_writing, file_for_saving;
    fstream file;
    string name_of_file, str1;
    int item0;
    int* array_from_file = new int[10000];

    std:: vector<int> vec1(60000);
    for (int i = 0; i < 60000; ++i) {
        vec1[i] = rand();
    }
    std:: vector<int> vec2(65000);
    for (int i = 0; i < 65000; ++i) {
        vec2[i] = rand();
    }
    std:: vector<int> vec3(70000);
    for (int i = 0; i < 70000; ++i) {
        vec3[i] = rand();
    }

    std:: vector<int> vec1_qs = vec1;
    std:: vector<int> vec1_ms = vec1;
    std:: vector<int> vec2_qs = vec2;
    std:: vector<int> vec2_ms = vec2;
    std:: vector<int> vec3_qs = vec3;
    std:: vector<int> vec3_ms = vec3;



    auto list1_bs = new LinkedList<int>(vec1.data(),vec1.size());
    auto list1_qs = new LinkedList<int>(vec1.data(),vec1.size());
    auto list1_ms = new LinkedList<int>(vec1.data(),vec1.size());

    auto list2_bs = new LinkedList<int>(vec2.data(),vec2.size());
    auto list2_qs = new LinkedList<int>(vec2.data(),vec2.size());
    auto list2_ms = new LinkedList<int>(vec2.data(),vec2.size());

    auto list3_bs = new LinkedList<int>(vec3.data(),vec3.size());
    auto list3_qs = new LinkedList<int>(vec3.data(),vec3.size());
    auto list3_ms = new LinkedList<int>(vec3.data(),vec3.size());

    Elem<int>* first_ms1 = list1_ms->LinkFirst();
    Elem<int>* first_ms2 = list2_ms->LinkFirst();
    Elem<int>* first_ms3 = list3_ms->LinkFirst();


    //for (int i = 0; i < n; ++i) {vec[i] = rand()%33;}
    //print_vec(vec1, 100);

    //std::cout << '\n';
    //quick_sort(vec,n-1,0);
    /*list1_bs->BubbleSortList(list1_bs->LinkFirst(),list1_bs->LinkLast());
    for (int i = 1; i <= 100; ++i) {
        std::cout << list1_bs->Get(i) << " ";
    }*/


    //быстрая сортировка вектора
    t_start = high_resolution_clock::now();
    //quick_sort(vec1_qs,vec1.size(),0);
    t_end = high_resolution_clock::now();
    time_span4 = duration_cast<duration<double>>(t_end - t_start);
    /*for (int i = 0; i < 60000; ++i) {
        std::cout << vec1_qs[i] << " ";
    }*/

    t_start = high_resolution_clock::now();
    //quick_sort(vec2_qs,vec1.size(),0);
    t_end = high_resolution_clock::now();
    time_span5 = duration_cast<duration<double>>(t_end - t_start);
    /*for (int i = 0; i < 65000; ++i) {
        std::cout << vec2_qs[i] << " ";
    }*/

    t_start = high_resolution_clock::now();
    //quick_sort(vec3_qs,vec1.size(),0);
    t_end = high_resolution_clock::now();
    time_span6 = duration_cast<duration<double>>(t_end - t_start);
    /*for (int i = 0; i < 70000; ++i) {
        std::cout << vec3_qs[i] << " ";
    }*/
    //сортировка слиянием вектора
    t_start = high_resolution_clock::now();
    //merge_sort(vec1_ms);
    t_end = high_resolution_clock::now();
    time_span7 = duration_cast<duration<double>>(t_end - t_start);
    /*for (int i = 0; i < 60000; ++i) {
        std::cout << vec1_ms[i] << " ";
    }*/
    t_start = high_resolution_clock::now();
    //merge_sort(vec2_ms);
    t_end = high_resolution_clock::now();
    time_span8 = duration_cast<duration<double>>(t_end - t_start);
    /*for (int i = 0; i < 65000; ++i) {
        std::cout << vec2_ms[i] << " ";
    }*/
    t_start = high_resolution_clock::now();
    //merge_sort(vec3_ms);
    t_end = high_resolution_clock::now();
    time_span9 = duration_cast<duration<double>>(t_end - t_start);
    /*for (int i = 0; i < 70000; ++i) {
        std::cout << vec3_ms[i] << " ";
    }*/
    //сортировка пузырьком вектора
    t_start = high_resolution_clock::now();
    //bubble_sort(vec1);
    t_end = high_resolution_clock::now();
    time_span1 = duration_cast<duration<double>>(t_end - t_start);
    /*for (int i = 0; i < 60000; ++i) {
        std::cout << vec1[i] << " ";
    }*/
    t_start = high_resolution_clock::now();
    //bubble_sort(vec2);
    t_end = high_resolution_clock::now();
    time_span2 = duration_cast<duration<double>>(t_end - t_start);
    /*for (int i = 0; i < 65000; ++i) {
        std::cout << vec2[i] << " ";
    }*/
    t_start = high_resolution_clock::now();
   // bubble_sort(vec3);
    t_end = high_resolution_clock::now();
    time_span3 = duration_cast<duration<double>>(t_end - t_start);
    /*for (int i = 0; i < 70000; ++i) {
        std::cout << vec3[i] << " ";
    }*/


    //быстрая сортировка cc
    t_start = high_resolution_clock::now();
    list1_qs->QuickSort(list1_qs->LinkFirst(),list1_qs->LinkLast());
    t_end = high_resolution_clock::now();
    time_span4 = duration_cast<duration<double>>(t_end - t_start);
    //for (int i = 1; i <= 60000; ++i) {std::cout << list1_qs->Get(i) << " ";}
    t_start = high_resolution_clock::now();
    list2_qs->QuickSort(list2_qs->LinkFirst(),list2_qs->LinkLast());
    t_end = high_resolution_clock::now();
    time_span5 = duration_cast<duration<double>>(t_end - t_start);
    //for (int i = 1; i <= 65000; ++i) {std::cout << list2_qs->Get(i) << " ";}
    t_start = high_resolution_clock::now();
    list3_qs->QuickSort(list3_qs->LinkFirst(),list3_qs->LinkLast());
    t_end = high_resolution_clock::now();
    time_span6 = duration_cast<duration<double>>(t_end - t_start);
    //for (int i = 1; i <= 70000; ++i) {std::cout << list3_qs->Get(i) << " ";}
    //сортировка слиянием cc
    t_start = high_resolution_clock::now();
    list1_ms->MergeSort(&first_ms1);
    t_end = high_resolution_clock::now();
    time_span7 = duration_cast<duration<double>>(t_end - t_start);
    /*for (int i = 1; i <= 60000; ++i) {
        std::cout << first_ms1->val << " ";
        first_ms1 = first_ms1->next;
    }*/
    t_start = high_resolution_clock::now();
    list2_ms->MergeSort(&first_ms2);
    t_end = high_resolution_clock::now();
    time_span8 = duration_cast<duration<double>>(t_end - t_start);
   /* for (int i = 1; i <= 65000; ++i) {
        std::cout << first_ms2->val << " ";
        first_ms2 = first_ms2->next;
    }*/
    t_start = high_resolution_clock::now();
    list3_ms->MergeSort(&first_ms3);
    t_end = high_resolution_clock::now();
    time_span9 = duration_cast<duration<double>>(t_end - t_start);
    /*for (int i = 1; i <= 70000; ++i) {
        std::cout << first_ms3->val << " ";
        first_ms3 = first_ms3->next;
    }*/
    //сортировка пузырьком cc
    t_start = high_resolution_clock::now();
    list1_bs->BubbleSortList(list1_bs->LinkFirst(),list1_bs->LinkLast());
    t_end = high_resolution_clock::now();
    time_span1 = duration_cast<duration<double>>(t_end - t_start);
       /* for (int i = 1; i <= 60000; ++i) {
            std::cout << list1_bs->Get(i) << " ";
        }*/
    t_start = high_resolution_clock::now();
    list2_bs->BubbleSortList(list2_bs->LinkFirst(),list2_bs->LinkLast());
    t_end = high_resolution_clock::now();
    time_span2 = duration_cast<duration<double>>(t_end - t_start);
        //for (int i = 1; i <= 65000; ++i) {std::cout << list2_bs->Get(i) << " ";}
    t_start = high_resolution_clock::now();
    list3_bs->BubbleSortList(list3_bs->LinkFirst(),list3_bs->LinkLast());
    t_end = high_resolution_clock::now();
    time_span3 = duration_cast<duration<double>>(t_end - t_start);
        //for (int i = 1; i <= 70000; ++i) {std::cout << list3_bs->Get(i) << " ";}

    file.open("comparison.csv", fstream::out | fstream::in | fstream::app);
    //Количество элементов;Время работы алгоритма сортировки пузырьком;Время работы алгоритма быстрой сортировки;Время работы алгоритма сортировки слиянием
    //file << 60000 << ";" << time_span1.count() << ";" << time_span4.count() << ";" << time_span7.count() << ";" << "\n";
    //file << 65000 << ";" << time_span2.count() << ";" << time_span5.count() << ";" << time_span8.count() << ";" << "\n";
    //file << 70000 << ";" << time_span3.count() << ";" << time_span6.count() << ";" << time_span9.count() << ";" << "\n";
    file.close();



    return 0;
}
