class SimpleModel(Module):
  __parameters__ = []
  __buffers__ = []
  training : bool
  def forward(self: __torch__.SimpleModel,
    x: float) -> float:
    return torch.add(x, 2)
