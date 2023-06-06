# Sorting algorithms

## Bubble sort

Bubble sort, also referred to as comparison sort, is a simple sorting algorithm that repeatedly goes through the list, compares adjacent elements and swaps them if they are in the wrong order. This is the most simplest algorithm and inefficient at the same time.
space complexity = 0(1) `Inplace sorting algorithm`
time compleaxity = 0(n^2)

## selection sort

The idea behind this algorithm is pretty simple. We divide the array into two parts: sorted and unsorted. The left part is sorted subarray and the right part is unsorted subarray. Initially, sorted subarray is empty and unsorted array is the complete given array.

We perform the steps given below until the unsorted subarray becomes empty:

- Pick the minimum element from the unsorted subarray.
- Swap it with the leftmost element of the unsorted subarray.
- Now the leftmost element of unsorted subarray becomes a part (rightmost) of sorted subarray and will not be a part of unsorted subarray.
  Time complexity: O(n^2)
  Space complexity: O(1)

## Insertion sort

Insertion sort is the sorting mechanism where the sorted array is built having one item at a time. The array elements are compared with each other sequentially and then arranged simultaneously in some particular order. The analogy can be understood from the style we arrange a deck of cards. This sort works on the principle of inserting an element at a particular position, hence the name Insertion Sort.
Time complexity: O(n^2)
Space complexity: O(1)

## Pattern

- When given numbers are from 1 to N. => use cyclic sort

## questions `leetcode`

- Find the only missing number
- Find all the numbers disappeared from the array
- find the duplicate numbers
- find all the duplicates from array
- find mismatch
