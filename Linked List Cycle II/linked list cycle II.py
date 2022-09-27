{\rtf1\ansi\ansicpg1252\cocoartf1404\cocoasubrtf470
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 # Definition for singly-linked list.\
# class ListNode:\
#     def __init__(self, x):\
#         self.val = x\
#         self.next = None\
\
class Solution:\
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:\
        slow = head\
        fast = head\
        \
        insPoint = None\
        \
        while True:\
            if (fast is None or fast.next is None):\
                return None\
            slow = slow.next\
            fast = fast.next.next\
            \
            if (slow == fast):\
                insPoint = slow\
                break\
        \
        start = head\
        while (start != insPoint):\
            start = start.next\
            insPoint = insPoint.next\
        \
        return start}