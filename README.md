# sycl_script

#### compiling ####
g++ ./show_unsupported_cuda_API.cpp -o show_unsupported_cuda_API  

#### shell process ####
for i in *.h; do ./show_unsupported_cuda_API $i; done  
