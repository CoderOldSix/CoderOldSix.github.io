---
title: 如何搭建自己的博客网站,并关联自定义域名（githubpages）
author: OldSix
date: 2021-01-03 18:32:00 -0500
categories: [Blogging, Tutorial]
tags: [github pages, custom domain]
---

本文主要概述，如何搭建自己的博客网站，并关联到自定义域名上。如何使用该主题，因为该主题比较特殊，因此，中间搭建过程可能比较麻烦，踩了几个坑，因此，在这里做一篇文章记录一下。

首先，创建自己的githubpages网站比较简单，所以在这里不做太多赘述，附上讲的比较好的链接：

* github官方介绍：[GitHub Pages 文档 - GitHub Docs](https://docs.github.com/cn/pages)
* 跟我一样的风格：[Getting Started](https://unrealdev.cn/posts/getting-started/)
* 普通一般风格：[零基础-通过Github Pages搭建个人博客_bilibili](https://www.bilibili.com/video/BV1Xh411b7wh?spm_id_from=333.880.my_history.page.click&vd_source=a25291d34476f766787af070326a91f5)

之所以把该网站的风格单独列出来，是因为该风格是因为该博客的风格使用了插件，而github为了安全考虑，限制了我们使用插件去生成其他页面文件。因此我们可以使用githubActions去构建站点。

简要概括整体步骤，先有一个整体的框架，如果想知道具体的可以先看上面的第二个和第三个链接。

步骤：

* 环境安装（windows电脑）：[windows安装Ruby等必要环境](https://jekyllrb.com/docs/installation/windows/)，Git安装；

* 创建仓库:username.github.io;

* git clone 到本地；

* 下载主题源代码：[Release地址](https://github.com/cotes2020/jekyll-theme-chirpy/releases)；

* 解压，并将目录里面的多个文件夹放到自己仓库的根目录下；

* 根目录下右键打开GitBash运行以下命令：

  * ```
    $ git add . 
    ```

  * ```
    $ git commit -m"SomeBlog"
    ```

  * ```console
    $ git push origin main
    ```

  * 注意：这里的分支名应该是你的主分支名，所有的操作也应该是你远程端，默认分支的名称，有的是默认master的，如果搞不懂就学一下git如何提交到远程仓库，以及每个命令的含义，这里不做赘述；

  * 运行以下命令：该命令会删除一些不必要的文件：

  * ```
    bash tools/init.sh
    ```

* 安装依赖项：

  * ```console
    $ bundle
    ```

* 使用：

  * 配置：
    * 修改如下根目录下_config.yml文件的变量，具体修改成什么值，文件中有注释参考：
      * url
      * avatar
      * timezone
      * lang

  * 自定义风格
    * 略，可不修改
  * 自定义静态资源
    * 略，可不修改

* 本地运行：

  * ```console
    $bundle exec jekyll s
    ```

  * 浏览器打开命令行上显示的地址，一般为：127.0.0.1:4000,查看是否正常运行，如果不行查找上述是否严格按照上述步骤实现；

* 部署：

  * 配置GitHub Actions 

    * 检查目标文件【.github/workflows/pages-deploy.yml】是否存在，如果没有则创建一个，并拷贝[SampleFile](https://github.com/cotes2020/jekyll-theme-chirpy/blob/master/.github/workflows/pages-deploy.yml.hook) 文件里的内容，注意检查branch的名称，需要跟自己的名称一致，该文件默认是master，其次需要将rubyversion更改为自己安装的ruby的version（上述的ruby安装选项已经告知如何查找ruby的ersion），因为安装的是dev版本的，所以，将它改为缩减版的版本即可，如我的：ruby 3.1.2p20 (2022-04-12 revision 4491bb740a) [x64-mingw-ucrt]，就直接更改为3.1.2。

    * 确保tools/deploy.sh文件存在，否则从[原仓库](https://github.com/cotes2020/jekyll-theme-chirpy/blob/master/tools/deploy.sh)上复制该文件；

    * 如果你的电脑不是linux系统，运行以下命令：

      * ```
        $bundle lock --add-platform x86_64-linux
        ```

      * ```
        $ git add .
        ```

      * ```
        $ git commit -m"+some log"
        ```

      * ```
        $ git push origin main
        ```

    * 经过上述操作，登录到 username.github.io 仓库，去看提交以后的编译操作，看是否编译成功，编译成功以后，就可以尝试用：yourusername.github.io来进行登陆了；

      

* 自定义域名：

  * 接下来，如果你想添加自定义域名，明天再写吧，已经凌晨两点了。哈哈哈！

* 快速刷新：

  * 


​	




