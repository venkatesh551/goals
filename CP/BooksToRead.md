
# Books to read

1. Art of Computer Programming (vol 1-4)
1. The Pragmatic Programmer
2. Effective Java
3. Refactoring: Improving the Design of Existing Code
4. Programming Pearls by Jon Bentley
5. Design Patterns by the Gang of Four
6. The Mythical Man Month
7. Clean Code: A Handbook of Agile Software Craftsmanship
10. Clean Architecture: A Craftsman's Guide to Software Structure and Design (Robert C. Martin)
11. The Clean Coder: A Code of Conduct for Professional Programmers
8. Algorithms (4th Edition) by Robert Sedgewick, Kevin Wayne
6. Hackers-Delight-Henry-S-Warren

Java :
1.  complete reference - syntax
2.  JLS
3.  Java Concurrency in Practice 1 Edition

3. Test Driven Development: By Example
4. Working Effectively with Legacy Code 1st Edition

# Of course, books alone don’t make you good developers - you need to practice and know your libraries and frameworks
# solve hacker-rank problems







2. http://www.cs.uu.nl/geobook/
6. https://www.amazon.com/Network-Flows-Theory-Algorithms-Applications/dp/013617549X

3. http://courses.csail.mit.edu/6.851/
   http://courses.csail.mit.edu/6.854/current/
4. http://www.infoarena.ro/blog/binary-search-shortlist
https://projecteuler.net/
http://www.cse.iitd.ernet.in/~sbaswana/Puzzles/Algo/algo.html


Must-read Books:
-------------------
Code Complete (2nd edition) by Steve McConnell
Structure and Interpretation of Computer Programs
The C Programming Language by Kernighan and Ritchie
Introduction to Algorithms by Cormen, Leiserson, Rivest & Stein
The Art of Computer Programming by Donald Knuth
Compilers: Principles, Techniques and Tools by Alfred V. Aho, Ravi Sethi and Jeffrey D. Ullman







I see coding competitions as an efficient and fun learning tool for  
algorithms/data structures/discrete math/coding/debugging. 



Communication skills: Communicating clearly is a skill and it has to be trained. University or coding contests don't put much emphasis on it.

(clarity) I had a hard time explaining my solutions clearly to other people during high school and first two years of university. I got much better when I started coaching kids for coding contests and writing articles about algorithms in a romanian publication. 

(English proficiency)  People with English as their second language might find it difficult to explain complex technical issues.
(introversion) Someone who's introverted might find it hard to verbalize his though process.




I think problems find people and people find problems. 
Depending of your interest (algorithms, distributed systems, 
natural language processing, machine learning, programming 
language design, compilers, low level programming, front end development, etc) 
you can find plenty of problems to tackle at Google. So it depends on you, 
not on Google if you use your knowledge or not.


K-way Merging :
---------------------
https://en.wikipedia.org/wiki/Merge_algorithm#cite_note-toolbox-2
https://en.wikipedia.org/wiki/K-Way_Merge_Algorithms

--
Naive algorithm
using heap
using Divide and conquer 
find no of comparisons for each solution ??
kWayMerge on lists and arrays :

Go through the stanford pdf, CLRS

random shuffling :
-------------------
    
https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle#The_modern_algorithm


MergeSort:
*************

Lower bound for sorting a Young tableaux.  (sedgewick)
 O(n^2 logn) for n*n

1. Merging two arrays of different lengths. Given two sorted arrays a[] and b[] of sizes M and N where M ≥ N, devise an algorithm to merge them into a new sorted array c[] using ~ N lg M compares.
Hint: use binary search.
Note: there is a lower bound of Omega(N log (1 + M/N)) compares. This follows because there are M+N choose N possible merged outcomes. A decision tree argument shows that this requires at least lg (M+N choose N) compares. We note that n choose r >= (n/r)^r.

2. Merging three arrays. Given three sorted arrays a[], b[], and c[], each of size N, design an algorithm to merge them into a new sorted array d[] using at most ~ 6 N compares in the worst case (or, even better, ~ 5 N compares).

3. Merging three arrays. Given three sorted arrays a[], b[], and c[], each of size N, prove that no compare-based algorithm can merge them into a new sorted array d[] using fewer than ~ 4.754887503 N compares in the worst case.

4. Ford-Johnson merge-insertion sort alg

* 5. Implementation is pending for 

 k-near-sorting. Suppose you have an array a[] of N distinct items which is nearly sorted: each item at most k positions away from its position in the sorted order. Design an algorithm to sort the array in time proportional to N log k.

6. https://www.reddit.com/r/programming/comments/9jqsi/how_to_merge_sorted_lists_with_olog_n_comparisons/


----
https://algorithmsandme.in/2014/12/07/find-kth-smallest-element-in-two-sorted-arrays/

Find median of two sorted arrays
Find intersction of 2 sorted arrays



https://stackoverflow.com/questions/500607/what-are-the-lesser-known-but-useful-data-structures
https://www.quora.com/Why-do-most-top-tech-companies-give-more-priority-to-algorithms-during-the-recruitment-process
https://www.quora.com/profile/Cosmin-Negruseri
http://translate.google.com/translate?hl=en&sl=auto&u=http%3A%2F%2Finfoarena.ro%2Ftraining-path








Lower bound is the best case running time. Lower bound is determined by the easiest input. It provides a goal for all inputs. 
Where as upper bound  is the worst case and is determined by the  most difficult input for a given algorithm.
Upper bounds provide guarantees for all inputs ie.. guarantees on performance of the algorithm when run on different inputs will not perform any worse than over the most difficult input.


big omega is lowerbound 

O-notation is upperbound





# Notes
----------

d-ary heap :

* The d-ary heap or d-heap is a priority queue data structure, a generalization of the binary heap in which the nodes have d children instead of 2

* 4-heaps may perform better than binary heaps in practice, even for delete-min operations

* parent of the item at position i (for any i > 0) is the item at position floor((i − 1)/d) and its children are the items at positions d * i + 1 through d * i + d.

*  




https://en.wikipedia.org/wiki/Double-ended_priority_queue
https://en.wikipedia.org/wiki/Min-max_heap
https://en.wikipedia.org/wiki/Order_statistic_tree
https://en.wikipedia.org/wiki/Pairing_heap
https://en.wikipedia.org/wiki/Fibonacci_heap  (CLRS)
https://en.wikipedia.org/wiki/Binomial_heap
https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree
https://en.wikipedia.org/wiki/Van_Emde_Boas_tree  (CLRS)

Greedy alg : https://en.wikipedia.org/wiki/Interval_scheduling 


http://www.spoj.com/problems/INTERVAL/








