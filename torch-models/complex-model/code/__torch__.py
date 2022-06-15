class MyModule(Module):
  __parameters__ = ["weight", ]
  __buffers__ = []
  weight : Tensor
  training : bool
  _is_full_backward_hook : Optional[bool]
  linear : __torch__.torch.nn.modules.linear.Linear
  def forward(self: __torch__.MyModule,
    input: Tensor) -> Tensor:
    weight = self.weight
    output = torch.add(weight, input)
    linear = self.linear
    return (linear).forward(output, )
