[![Build Status](https://travis-ci.org/aszxqw/keyword_server.png?branch=master)](https://travis-ci.org/aszxqw/keyword_server)
- - -

# 微型中文关键词抽取服务

## Introduction

`keyword_server` 是一个基于 [CppJieba] 包装而成 **中文关键词抽取服务** 。

[CppJieba] 项目自带 **关键词抽取** 的功能， 但是没有包装成服务，本来想改进 [CppJieba] 使之支持该服务。

但是考虑再三，为了避免 [CppJieba] 变得越来越臃肿，所以将该需求单独出来做成该项目。

这样好处也很明显，代码清凉解暑，不到50行代码的 `server.cpp` 就可以编译出一个 **中文关键词抽取服务** 。

## Feature

+ 支持`utf-8`编码。
+ 使用 `TF-IDF` 抽取算法。

## Usage

### Dependency

* `g++ (version >= 4.1 recommended) or clang++`;

### Download

```sh
git clone git://github.com/aszxqw/keyword_server.git
cd keyword_server
make
```

### server start

```
./keyword.server
```

### testing server

```
./curl.sh
```

## Contact

I will appreciate that if you issue any question or send mails to me (`wuyanyi09@foxmail.com`).

[CppJieba]:https://github.com/aszxqw/cppjieba
[simhash]:https://github.com/aszxqw/simhash
