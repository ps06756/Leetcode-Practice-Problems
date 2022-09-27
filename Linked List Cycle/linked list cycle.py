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
    def hasCycle(self, head: Optional[ListNode]) -> bool:\
        if (head is None or head.next is None):\
            return False\
        \
        first = head\
        second = head.next.next\
        \
        while first is not None and second is not None and second.next is not None:\
            if (first == second):\
                return True\
            \
            first = first.next\
            second = second.next.next\
        \
        return False\
        }