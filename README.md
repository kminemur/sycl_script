# sycl_script

Generate a csv file of unsupported API (based on DPCT messages) in a file.


#### compiling ####
g++ ./show_unsupported_cuda_API.cpp -o show_unsupported_cuda_API  

#### shell process ####
for i in *.h; do ./show_unsupported_cuda_API $i; done  
