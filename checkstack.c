/*
 * 检测本机的栈分配方向：
 * 策略：
 * 通过比较主函数中局部变量的地址(p)和子函数中局部变量的地址(q)，
 * *p先分配而*q后分配,如果p小，则栈是向上生长；如果p大，则栈是
 * 向下生长。
 * 其中，栈向上生长表示栈顶指针向内存地址大的方向移动
 * */
#include <stdio.h>

void check_stack(void *p)
{
    int bar;
    void *q = &bar;
    printf("p = %p, q = %p\n", p, q);
    printf("The stack grows %s.\n", (p<q) ? "up" : "down");
}

int main()
{
    int foo;
    check_stack(&foo);
    return 0;
}
