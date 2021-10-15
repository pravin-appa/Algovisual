#ifndef SORT_H
#define SORT_H

#include <utility>
#include "visual.h"



void bubbleSort(std::vector<std::pair<int, int>>& vec, Visual& visual)
{
    
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec.size() - i - 1; j++)
        {
            if (vec.at(j).first > vec.at(j + 1).first)
            {
                visual.sortingHelper(DELAY, {j, j + 1});
                std::swap(vec.at(j), vec.at(j + 1));
            }
        }
    }
}

void selectionSort(std::vector<std::pair<int, int>>& vec, Visual& visual)
{
    int iMin;
    for (int i = 0; i < vec.size(); i++)
    {
        iMin = i;
        for (int j = i + 1; j < vec.size(); j++)
        {
            if (vec.at(iMin).first > vec.at(j).first)
                iMin = j;
            visual.sortingHelper(DELAY, { i, iMin, j });
        }
        std::swap(vec.at(i), vec.at(iMin));
    }
}

int partition(std::vector<std::pair<int, int>>& vec, Visual& visual, int low, int high)
{
    int pivot = vec.at(high).first;
    int j = low - 1;

    for (int i = low; i <= high; i++)
    {
        if (vec.at(i).first < pivot)
        {
            j++;
            std::swap(vec.at(i), vec.at(j));
            visual.sortingHelper(DELAY, { i, j });
        }
    }
    std::swap(vec.at(j + 1), vec.at(high));
    visual.sortingHelper(DELAY, { j + 1, high });
    return j + 1;
}

void quickSort(std::vector<std::pair<int, int>>& vec, Visual& visual, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(vec, visual, low, high);

        quickSort(vec, visual, low, pivot - 1);
        quickSort(vec, visual, pivot + 1, high);
    }
}

void insertionSort(std::vector<std::pair<int, int>>& vec, Visual& visual)
{
    int key, j;
    for (int i = 1; i < vec.size(); i++)
    {
        j = i;
        key = vec.at(i).first;
        while (j > 0 && vec.at(j - 1).first > key)
        {
            vec.at(j).first = vec.at(j - 1).first;
            visual.sortingHelper(DELAY, { j, j - 1 });
            j--;
        }
        vec.at(j).first = key;
    }
}

void insertionSort(std::vector<int>& vec, Visual& visual)
{
    int key, j;
    for (int i = 1; i < vec.size(); i++)
    {
        j = i;
        key = vec.at(i);
        while (j > 0 && vec.at(j - 1) > key)
        {
            vec.at(j) = vec.at(j - 1);
            visual.sortingHelper(DELAY, { j, j - 1 });
            j--;
        }
        vec.at(j) = key;
    }
}

void merge(std::vector<std::pair<int, int>>& vec, Visual& visual, int begin, int mid, int end)
{
    int len1 = mid - begin + 1;
    int len2 = end - mid;

    std::vector<int> toHighlight;

    std::vector<std::pair<int, int>> left(len1);
    std::vector<std::pair<int, int>> right(len2);

    for (int i = 0; i < len1; i++)
        left.at(i).first = vec.at(begin + i).first;
    for (int i = 0; i < len2; i++)
        right.at(i).first = vec.at(mid + i + 1).first;

    int i = 0, j = 0;
    int k = begin;

    toHighlight.push_back(k);
    while (i < len1 && j < len2)
    {
        if (left.at(i).first <= right.at(j).first)
        {
            vec.at(k).first = left.at(i).first;
            toHighlight.push_back(begin + i);
            i++;
        }
        else
        {
            vec.at(k).first = right.at(j).first;
            toHighlight.push_back(mid + j + 1);
            j++;
        }
        visual.sortingHelper(DELAY, toHighlight);
        k++;
    }
    while (i < len1)
    {
        vec.at(k).first = left.at(i).first;
        toHighlight.push_back(begin + i);
        i++;
        k++;
        visual.sortingHelper(DELAY, toHighlight);
    }
    while (j < len2)
    {
        vec.at(k).first = right.at(j).first;
        toHighlight.push_back(mid + j + 1);
        j++;
        k++;
        visual.sortingHelper(DELAY, toHighlight);
    }
}

void mergeSort(std::vector<std::pair<int, int>>& vec, Visual& visual, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(vec, visual, left, mid);
        mergeSort(vec, visual, mid + 1, right);

        merge(vec, visual, left, mid, right);
    }
}


#endif
