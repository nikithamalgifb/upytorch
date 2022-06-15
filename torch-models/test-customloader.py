# This script tests the custom loader implementaion without micropython bindings
import importlib.util
import sys


# Module.py
file_path = "/home/rohanahluwalia/upytorch/torch-models/test_module.py"
module_name = "Module"
module_param = importlib.util.spec_from_file_location(module_name, file_path)
torch_nn_Module = importlib.util.module_from_spec(module_param)
sys.modules[module_name] = torch_nn_Module


module_param.loader.exec_module(torch_nn_Module)


#execute wanted script
new_file_path = "./simple-model/code/__torch__.py"
module_name = "Model"
new_param = importlib.util.spec_from_file_location(module_name, new_file_path)
new_module = importlib.util.module_from_spec(new_param)
sys.modules[module_name] = new_module

new_param.loader.exec_module(new_module)
