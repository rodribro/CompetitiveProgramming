### <b> Dynamic Programming </b>

### When to use?

1. count something, often the number of ways - Combinatorics
2. minimize or maximize certain value - Greedy?
3. Yes/No questions - Greedy?


### Problems

#### 1. Fibonacci (iterative)

```c++

#define N 100000
long long fib[N];
int main() {
    fib[0] = 0;
    fib[1] = 1;

    int 
    for(int i = 2; i < N; i++) {
        fib[i] = f[i-1] + f[i-2];
    }

}
```

#### 2. Combination Sum
 
