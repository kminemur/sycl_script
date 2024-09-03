# sycl_script

Generate a csv file of unsupported API (based on DPCT messages) in a file.


#### compiling ####
g++ ./show_unsupported_cuda_API.cpp -o show_unsupported_cuda_API  

#### Usage #####
./show_unsupported_cuda_API example.cpp  
  
CUDNN_ATTR_ENGINE_KNOB_INFO , 1  
CUDNN_KNOB_TYPE_COUNTS , 1  
CUDNN_TYPE_BACKEND_DESCRIPTOR , 1  



#### shell process ####
for i in *.h; do ./show_unsupported_cuda_API $i; done  
