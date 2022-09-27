{\rtf1\ansi\ansicpg1252\cocoartf1404\cocoasubrtf470
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 class Solution:\
    def solve(self, board: List[List[str]]) -> None:\
        m = len(board)\
        n = len(board[0])\
        \
        for i in range(m):\
            for j in range(n):\
                if (board[i][j] == 'O'):\
                    board[i][j] = 'U'\
        for j in range(n):\
            self.dfsCore(0, j, board)\
            self.dfsCore(m - 1, j, board)\
        \
        for i in range(m):\
            self.dfsCore(i, 0, board)\
            self.dfsCore(i, n - 1, board)\
        \
        for i in range(m):\
            for j in range(n):\
                if (board[i][j] == 'U'):\
                    board[i][j] = 'X'\
    \
    def dfsCore(self, row, col, board):\
        if (row >= 0 and row < len(board) and col >=0 and col < len(board[0]) and board[row][col] == 'U'):\
            board[row][col] = 'O'\
            self.dfsCore(row - 1, col, board)\
            self.dfsCore(row + 1, col, board)\
            self.dfsCore(row, col - 1, board)\
            self.dfsCore(row, col + 1, board)\
        }