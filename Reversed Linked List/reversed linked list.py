{\rtf1\ansi\ansicpg1252\cocoartf1404\cocoasubrtf470
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 # Definition for singly-linked list.\
# class ListNode:\
#     def __init__(self, val=0, next=None):\
#         self.val = val\
#         self.next = next\
class Solution:\
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:\
        self.newHead = None\
        if (head is not None):\
            lastNode = self.reverse(head)\
            lastNode.next = None\
        return self.newHead\
        \
    \
    def reverse(self, current):\
        if (current.next is None):\
            self.newHead = current\
            return current\
        else:\
            lastNode = self.reverse(current.next)\
            lastNode.next = current\
            return current}