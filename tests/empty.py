import torch


#simple torch.empty
a = torch.empty((2,3))
print(a)

# output to another tensor
b = torch.ones(1)
torch.empty((3,3), out=b)
print(b)
