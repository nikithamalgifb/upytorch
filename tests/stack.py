import torch
x = torch.ones(2, 3)
y = torch.ones(1)
z = torch.stack((x, x, x), 1)
print(z)
torch.stack((x, x, x), 1, out=y)
print(y)
