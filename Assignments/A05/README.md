## Assignment 5 - Run Times

### Loic Konan

<hr style="border:2px solid gray"> </hr>

- Count = **1048576**
  
- Complexity = **O(n^2)**
  
>
    int count = 0;
    int n = 1024;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            count++;
        }
    }
    cout << count << endl;

<hr style="border:2px solid gray"> </hr>

- Count = **523776**
  
- Complexity = **O(n^2)**
>
    int count = 0;
    int n = 1024;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            count++;
        }
    }
    cout << count << endl;

<hr style="border:2px solid gray"> </hr>

- Count = **536346624**

- Complexity = **O(n^3)**
>
    int count = 0;
    int n = 1024;
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < i; j++)
        {
            for(int k = 0; k < n; k++)
            {
                count++;
            }
        }
    }
    cout << count << endl;

<hr style="border:2px solid gray"> </hr>

- Count = **2048**

- Complexity = **O(n)**

>
    int count = 0;
    int n = 1024;
    for(int i = 0; i < 2*n; i++)
    {
        count++;
    }
    cout << count << endl;

<hr style="border:2px solid gray"> </hr>

- Count = **2097152**

- Complexity = **O(n^2)**
>
    int count = 0;
    int n = 1024;
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < 2*n; j++)
        {
            count++;
        }
    }
    cout << count << endl;

<hr style="border:2px solid gray"> </hr>

- Count = **524800**

- Complexity = **O(n^2)**
>
    int count = 0;
    int n = 1024;
    for(int i = 0; i < n; i++) 
    {
        count++;
    }
    for(int j = 0; j < n; j++)
    {
        for(int k = 0; k < j; k++)
        {
            count++;
        }
    }
    cout << count << endl;

<hr style="border:2px solid gray"> </hr>

- Count = **11264**

- Complexity = **O(n)**
>
    int count = 0;
    int n = 1024;
    int i = n;

    while(i > 0)
    {
        for(int j = 0; j < n; j++)
        {
            count++;
        }
        i /= 2;
        cout << i << endl;
    }
    cout << count << endl;

<hr style="border:2px solid gray"> </hr>

- Comparisons = **10**

- Complexity = **O(n)**
>
    bool found = 0;
    int n = 1024;
    int i = n;

    // assume loaded with random numbers
    // and in ascending order.
    int *A = new int[n];

    // Whats most number of comparisons ?
    // Whats the complexity ?
    found = BinarySearch (A, n);

<hr style="border:2px solid gray"> </hr>

- Count = **0**

- Complexity = **O(1)**
  
>
    int count = 0;
    int n = 1024;

    int i = n;
    while(i > 0)
    {
        cout << i << endl;
        i /= 2;  
    }
    cout<<count<<endl;

<hr style="border:2px solid gray"> </hr>
