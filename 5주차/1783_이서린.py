import sys
N, M=map(int,sys.stdin.readline().split())

if N==1:
  print(1)
elif N==2:
  print(min(4,int((M+1)/2)))
else:
  if M<=6:
      print(min(M,4))
  else:
      print(M-2)