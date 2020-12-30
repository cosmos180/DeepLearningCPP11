###
 # @Author: your name
 # @Date: 2020-09-24 21:48:15
 # @LastEditTime: 2020-10-19 11:03:34
 # @LastEditors: Please set LastEditors
 # @Description: In User Settings Edit
 # @FilePath: /conan-zlib/test_package/build.sh
### 
# conan export-pkg . DeepLearningCPP/0.1@bughero/Testing -pr=default
rm -rf test_package/build && conan test test_package DeepLearningCPP/0.1@bughero/Testing