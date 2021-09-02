2 stacks
    queue

        push method costly

            stack1 stack2
                stack1(add)

                    pop()
{
    shift of my stack1
        size of stack1 = 1;

    stack1 = stack2;
}

5 add(int ele)
{
    s2.push(ele);
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    s1 = s2;
    while (!s2.empty())
    {
        s2.pop();
    }
}