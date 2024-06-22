<div style="background-color: #EFEFEF; border: 3px solid #444; padding: 1rem; margin: 2rem 0; position: relative;">
  <div style="background: #FFEEAA; width: 7.5rem; border-right: 3px solid #444; border-bottom: 3px solid #444; text-align: center; position: absolute; left: -1rem; top: -1rem; padding: 2px 10px; font-weight: bold;">
    WARNING
  </div>
  Ceci est un message d'avertissement.
</div>


<u><font color=red>In this project, the subject was not very clear about the input numbers. So I considered that if the number was positive, the user had to write it without any sign '+'. Like in the examples given. Otherwise, the program send 'Error'. Just like when we communicate. If I'm 21, I say I'm 21, not +21.</u></font><br>
<b>push_swap Roadmap:<br>
First step:<br>
    - Error Management:<br>
        - If there is some letters => Return Error<br>
        - If there is duplicate => Return Error<br>
        - If there is numbers out of the INT range => Return Error<br>
        - Special case for the number: 18446744073709551615 which represents the unsigned long max. Sometimes, it can be considered as 1 => Return Error<br>
        - Special case for 2 arguments (argc = 2)<br>
            The user can enter number in that way: $> ./push_swap "1 2 3 4 5" (see manage_error_argc_is_2.c)<br>
            I handled the error in the a slight different way by using the ft_split function. The overall logic remains the same.<br>
    - Create the function to convert the numbers into a list (see create_list function in main.c).<br><br>
Second Step:<br>
    - Create the movements:<br>
        - the swap movement (see movement_swap.c)<br>
        - the rotate movement (see movement_rotate.c)<br>
        - the reverse rotate movement (see movement_reverse_rotate.c)<br>
        - the push movement (see movement_push.c)<br><br>
Third Step:
    - Creating the algorithm to sort all of the numbers passed in the prompt.
        - First step:
            - Create the functions to sort 2 and 3 numbers (see sort.c)
            - Create a function to find the median value of your stack (see find_the_median.c)<br>
            - Create a function that find the target node for each stack (see find_target_node_* functions in algorithm_utils.c)
            - Calculate the single cost of each nodes (see rate_single_cost function in algorithm_utils.2c)<br>
            - Calculate the total cost (called push_cost) for each nodes (see push_cost_total function in algorithm_utils.2c)<br>
            - Create a function to find the minimal push_cost (see min_push_cost function in min_max.c)<br><br>
            - Create the algorithm that will let you sort more than 3 numbers (see bigsort function in algorithm.c)<br>
                - I will suggest you to read this article to understand better my algorithm: https://medium.com/@ayogun/push-swap-c1f5d2d41e97 and to watch this video: https://www.youtube.com/watch?v=wRvipSG4Mmk<br>
                - Create the function to make the save movements (see save_movement function in algorithm.c)<br>
                - Create the function to move the minimal number at the top of the stack (see move_min_at_top function in algorithm.c)<br>
<br>

