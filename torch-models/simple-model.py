import torch


# Define a Simple Model class (Only using floats)
class SimpleModel(torch.nn.Module):
    def __init__(self):
        super(SimpleModel, self).__init__()

    def forward(self, x: float):
        new_x = x + 5
        return new_x


# Save the model as .pt file
model = torch.jit.script(SimpleModel())
torch.jit.save(model, "simple-model.pt")
