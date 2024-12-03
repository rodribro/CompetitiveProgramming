<b> 1. Cumulative Sums </b>

* Concept of cumulative sums/"prefix sums"
* Understand <b>Inclusion-Exclusion principle </b> and how to extend cumulative sums to more than onde dimension

<b> 2. Fenwick Trees (Binary Indexed Trees, a.k.a. BITs) </b>

* concept of a BIT, the way node store cumulative sums and its (simple) implementation
    * single updates, range queries [rangea(a,b) using bit(b)-bit(a-1)]
    * range updates, single queries [update(a,b,v) using update(a,v) and update(b+1,-v)]
    * range update, range queries [using two BITs]

* Understand how to adapt to more dimensions, and in particular to the case of 2D (a BIT of BITs)

<b> 3. Maximum Subarray Problem </b>

* determining maximum sum of a contiguous subsequence

* Kadane's Algorithm to solve this problem in linear time