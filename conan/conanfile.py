'''
Author: your name
Date: 2020-09-27 16:33:09
LastEditTime: 2021-03-26 11:58:30
LastEditors: Please set LastEditors
Description: In User Settings Edit
FilePath: /conan/conanfile.py
'''
from conans import ConanFile, CMake, tools


class DeepLearningCPPConan(ConanFile):
    name = "DeepLearningCPP"
    version = "0.1"
    license = "<Put the package license here>"
    author = "<Put your name here> <And your email here>"
    url = "<Package recipe repository url here, for issues about the package>"
    description = "<Description of DeepLearningCPP here>"
    topics = ("<Put some tag here>", "<here>", "<and here>")
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = {"shared": False}
    generators = "cmake"
    requires = "nlohmann_json/3.9.1"
    # no_copy_source = True
    exports_sources = "CMakeLists.txt", "src/*"


    # def source(self):
        # self.run("git clone https://github.com/conan-io/hello.git")
        # This small hack might be useful to guarantee proper /MT /MD linkage
        # in MSVC if the packaged project doesn't have variables to set it
        # properly
#         tools.replace_in_file("hello/CMakeLists.txt", "PROJECT(HelloWorld)",
#                               '''PROJECT(HelloWorld)
# include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
# conan_basic_setup()''')

    def build(self):
        cmake = CMake(self)
        # cmake.configure(source_folder="src")
        cmake.build()

        # Explicit way:
        # self.run('cmake %s/hello %s'
        #          % (self.source_folder, cmake.command_line))
        # self.run("cmake --build . %s" % cmake.build_config)

    def package(self):
        self.copy("*", dst="include", src="src")
        self.copy("*hello.lib", dst="lib", keep_path=False)
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.dylib", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)

    def package_id(self):
            self.info.header_only()

    def package_info(self):
        self.cpp_info.libs = ["DeepLearningCPP"]

