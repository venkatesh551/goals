D.A. Patterson and J.L. Hennessy. Computer Architecture: A Quantitative Approach. Morgan Kaufmann,

DSGT : https://www2.cs.sfu.ca/~ggbaker/zju/math/
https://en.wikipedia.org/wiki/Selection_algorithm
https://www.cs.sfu.ca/~ggbaker/zju/math/recurrence.html
leetcode tags :  https://leetcode.com/tag/array/

https://en.wikipedia.org/wiki/Edsger_W._Dijkstra

manuscripts

http://www.spoj.com/problems/tags

# Learn in-detail about recurrence relations, Time-Complexity Notations : Big-O, Big-Omega, Theta

3. complete CLRS book  (including problems)
5. Programming pearls

# your Goal : Understand every Concept, Mathematical proof in sedgewick, CLRS, Solve problems

CLRS :
------
Practice a lot.
Try solving the problems first.
Discuss the problems with friends.

Write-code, and test-code for verification

# goals  : stick to 3 books :  CP-3, CLRS, sedgewick

1. complete edx course
2. complete sedgewick book, vedio lectures   (including problems)
3. complete CP-3 book  (including problems)
only concept from CLRS


If you're changing the world, you're working on important things. You're excited to get up in the morning.

You never lose a dream. It just incubates as a hobby.

perseverance = persistence in doing something despite difficulty or delay in achieving success.

You shoud have solid thoeretical background, and then solve problems


In CLRS   :  Read Part-II (sorting), Part-III (DS), 
             Part- IV (DP, greedy), Part-VI (Graphs)

Most important thing you need to understand is How many comparisons are made in the : worst-case, Best-case, avg-case 

https://www.coursera.org/learn/algorithms-part1/home/welcome


sorting:
--------
Read Theory about Merge-sort : wikipedia, 

1. Solve sedgewick-exercises  (book)  :  3-way mergesort, Multiway mergesort, 2 on LL
2. http://algs4.cs.princeton.edu/22mergesort/
3. understand Bottom-up MS
---
4. Read theory about Quick Sort : wikipedia, sedgewick-exercises, CLRS-exercises,
    solve Problems : edx, HR

https://cs.stackexchange.com/questions/11458/quicksort-partitioning-hoare-vs-lomuto

hoare's partition, place pivot in it's correct position, implement  : 45 mins
https://en.wikipedia.org/wiki/Dutch_national_flag_problem
https://www.hackerrank.com/challenges/quicksort1
1. https://www.hackerrank.com/challenges/quicksort2
2. implement 3-way partition qsort
3. princeton vedio, sedgewick book,
We are given an array and we want to find it's kth smallest, K-th biggest element.
http://www.spoj.com/problems/KSMALL/


https://www.coursera.org/learn/algorithms-part1/quiz/iH9u8/interview-questions-optional (3 problems)

   3. 2.3.15, 16, 17, 18, 19 sedgewick  : Median-of-three partitioning

    Median of 3 numbers in 2 comparisons ??
    Median of 5 numbers in 6 comparisons ??
    sort 5 numbers in 7 comparisons
    5-way partition qsort
    
    https://cs.stackexchange.com/questions/44981/least-number-of-comparisons-needed-to-sort-order-5-elements/44982#44982
    https://cs.stackexchange.com/questions/45374/prove-that-minimal-number-of-comparisons-to-find-median-among-five-elements-is-5
   
   In partition why i <= j  ?? why not i < j ??
   Because when i == j, there exist a test-case where v[j] > pivot,
   we need to swap v[j] with pivot (= v[low]) , for that purpose v[j] should be <= pivot
   
   e.g : 2 3 4 1 4 , pivot is first element


   4. 2.3.20 to 2.3.24 sedgewick
   --

   5. 2.3.25 to 2.3.31 sedgewick
   --
   6. sedgewick Web Exercises 1 to 4    http://algs4.cs.princeton.edu/23quicksort/
   --  
      sedgewick Web 5 to 8
   --
   dual pivot
   three pivot
      
   8. edx-problems : https://courses.edx.org/courses/course-v1:ITMOx+I2CPx+1T2017/courseware
   
   A Killer Adversary for Quicksort
   sample sort
   Median of 3 numbers in 2 comparisons ??
   sedgewick :  qsort :  2.3.21 Lower bound for sorting with equal keys ??

   9. coursera : Merge-sort vedio and assignment

5. Heap-sort : wikipedia, CLRS-exercises, sedgewick-exercises
    solve Problems : SPOJ, edx
    priority_queue problems
    
    
    https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=633
  
    http://www.spoj.com/problems/tag/priority-queue
    http://www.spoj.com/problems/tag/sliding-window-1
    
    http://www.spoj.com/problems/RMID2/ 
    http://www.spoj.com/problems/ARRAYSUB/
    https://www.hackerrank.com/domains/data-structures/heap
    
    https://leetcode.com/tag/heap/

1. skyline problem : https://briangordon.github.io/2014/08/the-skyline-problem.html

    * 8. http://www.zrzahid.com/the-skyline-problem/
    * 2. http://www.zrzahid.com/maximum-number-of-overlapping-intervals/
    * 1. https://leetcode.com/problems/non-overlapping-intervals/description/
    * 3. cpu overload
    * 4. http://www.spoj.com/problems/QUEST5/
    * 6. http://www.spoj.com/problems/BUSYMAN/


2. Super Ugly Number
3. Split Array into Consecutive Subsequences
4. Kth Smallest Element in a Sorted Matrix
5. Trapping Rain Water II
6. http://www.spoj.com/problems/EXPEDI/
7. http://www.spoj.com/problems/LAZYPROG/
8. http://www.spoj.com/problems/PRO/

9. Sedgewick Book, vedio, exercises

EDX

  http://acgtun.com/leetcode/solution
smooth-sort


6. Read theory about (Counting sort, Bucket sort, Radix Sort) : wikipedia, CLRS book-exercises
    solve Problems : edx, HR

http://www.spoj.com/problems/LEXISORT/


7. CLRS book-part2 : order-statistics 
    edx, exercises, 

8. Bubble-sort: wikipedia, read Chapter 2 in CLRS, elementary sorts in Sedgewick
    solve Problems : HE, HR

    Tim-sort
    coursera problems : solve k-small, k-largest on 2 sorted arrays, Decimal dominant
    Programming Assignment: Collinear Points
    http://www.spoj.com/problems/tag/divide-and-conquer
    
    Time-complexity by recurrence relations, prove it mathematically
    
    Prove Build-max-heap asymptotic tight bound is O(n) 
    print min-heap in level-order traveral
    
http://www.spoj.com/problems/tag/sorting


---

9. Searching : 
-------------
linear, Binary, Ternary  : wikipedia

Resume EDX : Go through the vedio one more time
Solve edx problems

http://www.spoj.com/BSCPROG/


10. edx : Graph-Theory :
    edx problems
    Chapter 4 : Graphs in sedgewick (exercises)
    Part-VI (Graphs) -- CLRS

11. Read CP-3 : Chapter-1 : solve all problems in UVA OJ

12. Read CP-3 : Chapter-2 : DS 
    
    Read CLRS : Part-III (DS) (solve problems in each DS)
    Chapter-3 in sedgewick
    Solve problems in UVA OJ

13. Read CP-3 :  Chapter-3  :  DP
    Read CLRS :  Part- IV (DP, greedy) ; solve problems
    Solve problems in UVA OJ

14. Read CP-3 : Chapter-4 : Graph Theory

CLRS part: VII  selected topics
    
15. Read CP-3 : Chapter-5 : Mathematics 

16. Read CP-3 : Chapter-6 : String processing

    chapter 5 : sedgewick




HackerRank : Insertion Sort Advanced Analysis

References:
-----------
https://www.codechef.com/problems/SORTING
http://www.spoj.com/problems/tag/sortings
https://www.hackerearth.com/practice/algorithms/sorting/
https://www.hackerrank.com/domains/algorithms/arrays-and-sorting

DS
----
https://www.hackerrank.com/domains/data-structures/
https://www.hackerearth.com/practice/data-structures/








https://github.com/haseebr/competitive-programming/tree/master/Materials

If the input array is already sorted, insertion sort performs 
as few as n-1 comparisons, thus making insertion sort more efficient 
when given sorted or "nearly sorted" arrays.


Merge sort is often the best choice for sorting a linked list: in this situation it is relatively easy to implement a merge sort in such a way that it requires only Θ(1) extra space, and the slow random-access performance of a linked list makes some other algorithms (such as quicksort) perform poorly, and others (such as heapsort) completely impossible.

-----

Discrete math of different kinds. More specifically:
Logic and proof technologies, like math induction or proof by contrapositive.
Graphs of all kinds.
Set theory. Basics, no need to distinguish infinite sets cardinality or learn ZFC. Inclusion–exclusion principle, for instance.
Combinators. Binomial coefficients, different tricks about calculating amount of something (similar tricks can be used in programming to make problem easier to solve) - all are very useful.
Asymptotical analysis - again, basics. For example, remembering that sum of harmonic series is logarithm is very useful (e.g. in naive Eratosthenes sieve)
Probability theory - useful in corresponding problems or when you're trying to invent randomized algorithm. Also a good excercise for your brain.
Number theory - it's useful sometimes in corresponding problems. Not very useful outside of number theory problems.

---


Don't delegate: Do everything you can yourself to make things go faster.
Don't get in the way if you're not adding value. Let the people actually doing the work talk to each other while you go do something else.
Don't be a bureaucrat.
Ideas are more important than age. Just because someone is junior doesn't mean they don't deserve respect and cooperation.
The worst thing you can do is stop someone from doing something by saying, "No. Period." If you say no, you have to help them find a better way to get it done


http://infolab.stanford.edu/~ullman/focs/ch05.pdf

http://fusharblog.com/3-ways-to-define-comparison-functions-in-cpp/


