# Push Swap

A sorting algorithm implementation that sorts a stack of integers using a limited set of operations on two stacks.

## 📋 Project Overview

Push Swap is a project that implements an efficient sorting algorithm using two stacks (A and B) and a limited set of operations. The goal is to sort a sequence of integers using the minimum number of operations possible.

## 🎯 Problem Statement

Given a stack A containing a sequence of integers, sort them in ascending order using only the following operations:
- **sa/sb/ss**: Swap the top two elements of stack A/B/both
- **ra/rb/rr**: Rotate stack A/B/both (move top element to bottom)
- **rra/rrb/rrr**: Reverse rotate stack A/B/both (move bottom element to top)
- **pa/pb**: Push top element from one stack to the other

## 🏗️ Project Structure

```
push_swap/
├── inc/
│   └── push_swap.h          # Header file with all declarations
├── srcs/
│   ├── main.c               # Program entry point
│   ├── list_utils.c         # Linked list utilities
│   ├── push_swap_utils.c    # Utility functions (atoi, split, etc.)
│   ├── manage_errors.c      # Error handling for normal arguments
│   ├── manage_errors2.c     # Additional error handling
│   ├── manage_errors_argc_is_2.c  # Error handling for single string input
│   ├── movement_swap.c      # Swap operations (sa, sb, ss)
│   ├── movement_rotate.c    # Rotate operations (ra, rb, rr)
│   ├── movement_reverse_rotate.c  # Reverse rotate operations (rra, rrb, rrr)
│   ├── movement_push.c      # Push operations (pa, pb)
│   ├── sort.c               # Sorting algorithms for 2-3 numbers
│   ├── algorithm.c          # Main sorting algorithm for larger stacks
│   ├── algorithm_utils.c    # Algorithm helper functions
│   ├── algorithm_utils2.c   # Additional algorithm utilities
│   ├── find_the_median.c    # Median calculation
│   ├── min_max.c            # Min/max element finding
│   └── ft_split.c           # String splitting utility
├── Makefile                 # Build configuration
└── README.md               # This file
```

## 🧮 Data Structure

The project uses a linked list structure to represent stacks:

```c
typedef struct s_list
{
    long int        nb;         // The number value
    int             index;      // Position in the stack
    int             single_cost; // Cost to move to top
    int             push_cost;   // Total cost including push
    struct s_list   *target;    // Target position in other stack
    struct s_list   *next;      // Next node
} t_list;
```

## 🔧 Core Components

### 1. Error Management
- **Input Validation**: Checks for non-numeric characters, duplicates, and integer overflow
- **Range Validation**: Ensures numbers are within INT_MIN/INT_MAX range
- **Special Cases**: Handles the unsigned long max value (18446744073709551615)
- **Flexible Input**: Supports both multiple arguments and single string input

### 2. Stack Operations
- **Swap Operations**: `sa`, `sb`, `ss` - Swap top two elements
- **Rotate Operations**: `ra`, `rb`, `rr` - Move top element to bottom
- **Reverse Rotate**: `rra`, `rrb`, `rrr` - Move bottom element to top
- **Push Operations**: `pa`, `pb` - Move top element between stacks

### 3. Sorting Algorithms

#### Small Stacks (2-3 numbers)
- **2 numbers**: Simple swap if needed
- **3 numbers**: Optimized algorithm with maximum 3 operations

#### Large Stacks (4+ numbers)
The algorithm uses a sophisticated cost-based optimization approach with the following key concepts:

##### 1. Target Node Concept
For each node in stack B, we find its **target node** in stack A:
- **Target**: The closest bigger number in stack A, OR the minimum number if no bigger number exists
- **Purpose**: Determines where each B node should be placed in stack A

**Example 1:**
```
Stack A: 2 5 4 8
Stack B: 1 3 9 7 6

Target mapping:
- B:1 → A:2 (closest bigger)
- B:3 → A:4 (closest bigger) 
- B:6 → A:8 (closest bigger)
- B:7 → A:8 (closest bigger)
- B:9 → A:2 (minimum, since 9 > all numbers in A)
```

**Example 2:**
```
Stack A: 3 4 6 7
Stack B: 1 2 5 8 9

Target mapping:
- B:1 → A:3 (closest bigger)
- B:2 → A:3 (closest bigger)
- B:5 → A:6 (closest bigger)
- B:8 → A:3 (minimum, since 8 > all numbers in A)
- B:9 → A:3 (minimum, since 9 > all numbers in A)
```

##### 2. Push Cost Calculation
The **push_cost** represents the total number of operations needed to:
1. Move a node to the top of its current stack
2. Move its target node to the top of the other stack
3. Perform the push operation (from stack B to stack A for example)

**Example 1:**
```
Stack A: 3 4 6 7 1
Stack B: 5 2 9 8

For B:5 (target A:6):
- Cost to move B:5 to top = 0 operation (already at top)
- Cost to move A:6 to top = 2 operations  
- Total push_cost = 0 + 2 = 2 operations
```

**Example 2:**
```
Stack A: 2 5 4 8
Stack B: 1 3 9 7

For B:1 (target A:2):
- Cost to move B:1 to top = 0 operations (already at top)
- Cost to move A:2 to top = 0 operations (already at top)
- Total push_cost = 0 + 0 = 0 operations (undoubtedly optimal!)
```

##### 3. Median Calculation
The median helps optimize the chunking strategy:
- **Definition**: The middle value when numbers are sorted
- **Even-sized stacks**: Take the first number as median for simplicity
- **Purpose**: Helps decide whether to rotate stack B after pushing

**Example 1:**
```
Numbers: 2 9 8 5 3 4 6 7 1
Sorted:  1 2 3 4 5 6 7 8 9
Median:  5 (middle value)
```

**Example 2:**
```
Numbers: 3 1 4 2
Sorted:  1 2 3 4  
Median:  2 (first number for even-sized stack)
```

##### 4. Movement Optimization
To minimize operations, the algorithm uses the most efficient movement:
- **Before middle**: Use rotate (ra/rb)
- **After middle**: Use reverse_rotate (rra/rrb)

**Example:**
```
Stack: 1 2 3 4 5 6 7 8 9
To move 7 to top:
- 7 is after middle (position 7/9)
- Use reverse_rotate: 3 operations instead of 6
```

##### 5. Complete Algorithm Steps

**Phase 1: Push to Stack B**
```
Initial:
Stack A: 2 9 8 5 3 4 6 7 1
Stack B: empty

Step 1: Push 2 to B
- 2 > median(5)? No → leave at top
Stack A: 9 8 5 3 4 6 7 1
Stack B: 2

Step 2: Push 9 to B  
- 9 > median(5)? Yes → rotate B
Stack A: 8 5 3 4 6 7 1
Stack B: 2 9

Continue until stack A has only 3 numbers...
```

**Phase 2: Sort Stack A**
```
When A has 3 numbers: 
Stack A: 6 7 1
Stack B: 4 3 5 2 9 8

Stack A: 1 6 7
Stack B: 4 3 5 2 9 8
```

**Phase 3: Push Back to A (Cost-Based)**
```
Current state:
Stack A: 1 6 7
Stack B: 4 3 5 2 9 8

For each B node, calculate push_cost:

B:4 (target A:6 - closest bigger):
- Cost to move B:4 to top = 0 operation (already at top)
- Cost to move A:6 to top = 1 operation (rotate A)
- Total push_cost = 0 + 1 = 1 operation

B:3 (target A:6 - closest bigger):
- Cost to move B:3 to top = 1 operation (rotate B)
- Cost to move A:6 to top = 1 operation (rotate A)
- But we can save 1 mouvement by doing *Rotate A & B* (rr) 
- Total push_cost = 1 operation (with rr)

B:5 (target A:6 - closest bigger):
- Cost to move B:5 to top = 2 operations (rotate B twice)
- Cost to move A:6 to top = 1 operation (rotate A)
- But we can save 1 mouvement by doing *Rotate A & B* (rr) 
- Total push_cost = 1 + 1 = 2 operations (rr & rb)

B:2 (target A:6 - closest bigger):
- Cost to move B:2 to top = 3 operations (rotate B three times)
- Cost to move A:6 to top = 1 operation (rotate A)
- But we can save 1 mouvement by doing *Rotate A & B* (rr)
- Total push_cost = 1 + 2 = 3 operations (rr & rb & rb)

B:9 (target A:1 - minimum, since 9 > all numbers in A):
- Cost to move B:9 to top = 2 operations (reverse rotate B twice)
- Cost to move A:1 to top = 0 operation (already at top)
- Total push_cost = 2 + 0 = 2 operations

B:8 (target A:1 - minimum, since 8 > all numbers in A):
- Cost to move B:8 to top = 1 operation (reverse rotate B)
- Cost to move A:1 to top = 0 operation (already at top)
- Total push_cost = 1 + 0 = 1 operation

Choose B:4 (lowest push_cost = 1)
*We could have choose also B:3 and B:8, but I take the one that comes first - This could be + optimized*
Push B:4 to A:
- We execute the 1 operation previously calculated, which is Rotate A. Now the node 1 is at the bottom of the stack A. We can execute the push operation (from B to A) because the node and his target are at to the top of their respectives stacks.
Stack A: 4 6 7 1
Stack B: 3 5 2 9 8

Recalculate push_costs for remaining B nodes and repeat until Stack B is empty...

Next push:
Choose B:3
Stack A: 3 4 6 7 1
Stack B: 5 2 9 8

Next push:
Choose the good target node - B:2
Stack A: 2 3 4 6 7 1
Stack B: 9 8 5

Next push:
Choose B:9
Stack A: 9 1 2 3 4 6 7
Stack B: 8 5

Next push:
Choose B:8
Stack A: 8 9 1 2 3 4 6 7
Stack B: 5

Next push:
Choose B:5
Stack A: 5 6 7 8 9 1 2 3 4
Stack B: empty
```

**Phase 4: Final Optimization**
```
When all numbers are back in A:
Stack A: 5 6 7 8 9 1 2 3 4
Find minimum number (1) and move it to top:
- 1 is at position 6/9 (after middle)
- Use reverse_rotate: 4 operations instead of 6

Final result:
Stack A: 1 2 3 4 5 6 7 8 9
Stack B: empty

The stack is now sorted in ascending order!
```

##### 6. Performance Optimization
This algorithm achieves excellent performance:
- **100 numbers**: ≤ 700 operations
- **500 numbers**: ≤ 5500 operations
- **1000+ numbers**: Efficient scaling

The key to efficiency is always choosing the node with the **minimum push_cost**, ensuring optimal movement patterns and minimizing total operations.

## 🚀 Usage

### Compilation
```bash
make
```

### Running the Program
```bash
# Multiple arguments
./push_swap 3 1 4 2 5

# Single string input
./push_swap "3 1 4 2 5"
```

### Available Make Commands
- `make` or `make all`: Compile the program
- `make clean`: Remove object files
- `make fclean`: Remove object files and executable
- `make re`: Recompile everything

## 📊 Performance

The algorithm is designed to be efficient:
- **2 numbers**: Maximum 1 operation
- **3 numbers**: Maximum 3 operations
- **5 numbers**: Maximum 12 operations
- **100 numbers**: Maximum 700 operations
- **500 numbers**: Maximum 5500 operations

## 🔍 Key Features

1. **Robust Error Handling**: Comprehensive input validation
2. **Flexible Input**: Supports both argument-based and string-based input
3. **Optimized Algorithm**: Uses cost-based optimization for large stacks
4. **Memory Management**: Proper memory allocation and deallocation
5. **Clean Code**: Well-structured and documented codebase (even if it could be better without the norminette)

## 🧠 Algorithm Insights

The main algorithm is inspired by the concept of finding the optimal movement for each number by calculating:
- **Finding Median Value**: Reduce the number of mouvements depending on where the median is
- **Single Cost**: Operations needed to move a number to the top of its stack
- **Target Position**: Where the number should be placed in the other stack
- **Total Push Cost**: Combined cost of moving to top and pushing to target

## 📝 Notes

- Positive numbers should be entered without the '+' sign
- The program handles edge cases like integer overflow and invalid inputs
- The algorithm is designed to work efficiently with the 42 school's push_swap checker

## 📚 References

For a deeper understanding of the push_swap algorithm and optimization strategies:

- **[Push Swap Algorithm Explained](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)** - A comprehensive Medium article explaining the cost-based optimization approach
- **[Push Swap Visualization](https://www.youtube.com/watch?v=wRvipSG4Mmk)** - YouTube video demonstrating the algorithm in action with visual examples

## 🤝 Contributing

This project was developed as part of the 42 school curriculum. The implementation focuses on efficiency and clean code practices while meeting the project requirements.

