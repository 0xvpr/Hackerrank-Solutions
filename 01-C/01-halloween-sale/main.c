#include <stdio.h>

static int price;
static int discount;
static int min_discount;
static int budget;

int main(void)
{
    if (!scanf("%d %d %d %d", &price, &discount, &min_discount, &budget))
    {
        return 1;
    }
    
    int total = 0;
    int rate = price;
    if (budget  >= rate)
    {
        budget -= rate;
        ++total;
    }
    
    while (budget - rate >= 0)
    {
        if (rate > min_discount)
        {
            rate -= discount;
        }
        
        if (rate <= min_discount)
        {
            rate = min_discount;
        }
        
        budget -= rate;
        ++total;
    } 
    fprintf(stdout, "%d\n", total);
    
    return 0;
}
