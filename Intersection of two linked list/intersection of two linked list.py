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
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:\
        m = self.findLength(headA)\
        n = self.findLength(headB)\
        fp = headA\
        sp = headB\
        if (m <= n):\
            for i in range(n - m):\
                sp = sp.next\
        else:\
            for i in range(m - n):\
                fp = fp.next\
                \
        while fp is not None:\
            if (fp == sp):\
                return fp\
            fp = fp.next\
            sp = sp.next\
        \
        return None\
    \
    def findLength(self, head):\
        length = 0\
        curr = head\
        while (curr is not None):\
            curr = curr.next\
            length += 1\
        return length}