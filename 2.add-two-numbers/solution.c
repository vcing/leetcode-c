#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode
{
   int val;
   struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
   struct ListNode *result = (struct ListNode *)malloc(sizeof(struct ListNode));
   struct ListNode *answer = result;
   result->val = 0;
   result->next = NULL;
   int increament = 0;

   if (l1->val != NULL || l2->val != NULL)
   {
      const int sum = l1->val + l2->val;
      result->val = sum >= 10 ? sum % 10 : sum;
      increament = sum >= 10;
   }

   while ((l1 && l1->next) || (l2  && l2->next))
   {
      l1 = l1 ? l1->next : NULL;
      l2 = l2 ? l2->next : NULL;
      struct ListNode *next = (struct ListNode *)malloc(sizeof(struct ListNode));
      const int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + increament;
      next->val = sum >= 10 ? sum % 10 : sum;
      next->next = NULL;
      result->next = next;
      result = next;
      increament = sum >= 10;
   }

   if (increament)
   {
      struct ListNode *next = (struct ListNode *)malloc(sizeof(struct ListNode));
      next->next = NULL;
      next->val = 1;
      result->next = next;
      result = next;
   }

   return answer;
}
