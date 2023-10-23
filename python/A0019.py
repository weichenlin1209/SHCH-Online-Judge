year = int(input())
month = year * 12
y_rate = float(input())
t_money = int(input()) * 10000
m_rate = y_rate / 12

A = m_rate * (((1+m_rate)**month) / ((1+m_rate)**month - 1))
M = t_money * int(A + 0.5)

MR = t_money * A
MM = M - MR

print(int(abs(MM)+0.5))