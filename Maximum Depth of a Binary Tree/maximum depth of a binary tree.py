{\rtf1\ansi\ansicpg1252\cocoartf1404\cocoasubrtf470
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 # Definition for a binary tree node.\
# class TreeNode:\
#     def __init__(self, val=0, left=None, right=None):\
#         self.val = val\
#         self.left = left\
#         self.right = right\
class Solution:\
    def maxDepth(self, root: Optional[TreeNode]) -> int:\
        if (root is None):\
            return 0\
        else:\
            return max(self.maxDepth(root.left) + 1, self.maxDepth(root.right) + 1)\
        }