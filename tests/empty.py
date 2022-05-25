import torch

#torch.empty() returns a tensor filled with unitialized data (which means it is not always 0)
a = torch.empty((2, 3), dtype=torch.int64)
print(a)

# output to another tensor
b = torch.ones(1)
torch.empty((3, 3), dtype=torch.int64, out=b)
print(b)
