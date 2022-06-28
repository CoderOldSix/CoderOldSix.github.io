---
title: 如何搭建自己的博客网站,并关联自定义域名
author: CoderOldSix
date: 2022-06-27 18:32:00 -0500
categories: [Blogging, Tutorial]
tags: [github pages, custom domain]
---

本文主要概述，如何搭建自己的博客网站，并关联到自定义域名上。如何使用该主题，因为该主题比较特殊，因此，中间搭建过程可能比较麻烦，踩了几个坑，因此，在这里做一篇文章记录一下。

本文除了介绍有以下几个方面：

* <u>搭建username.github.io网站；</u>

  * 快速刷新自定义域名和github.io的关联关系

* <u>添加评论功能；</u>

* <u>关联自定义域名；</u>

  

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

    * 如果你使用的<u>**本地电脑**</u>不是linux系统，运行以下命令：

      * ```
        $ bundle lock --add-platform x86_64-linux
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

    * 注意：在做下面的步骤之前最好确认username.github.io 网址可以正常访问；


* 自定义域名：

  * 首先，你要自己申请域名[阿里云](https://wanwang.aliyun.com/?spm=5176.1830550.0.0.5b7c5f0fXlKyZu)为例；
  * 申请完成以后，可能需要实名认证；
  * 然后做DNS解析，[DNS解析](https://www.bilibili.com/video/BV1yA41187ok?spm_id_from=333.880.my_history.page.click&vd_source=a25291d34476f766787af070326a91f5)；
    * 因为上述连接中是二级域名，因此，它上面提到的填写“blog”的地方可以不写内容；
    * 需要注意的是，AAAA记录也是可以写的，你的解析写多了，并不影响正常的使用；
  * 上述完成以后，就可以在自己的github.io仓库的setings->pages界面设置外部链接了，如果你的DNS解析填写没有问题，可以直接将自己的域名写入，exp：unrealdev.cn;
  * 等上述完成以后，并且解析无误，外部链接就可以正常访问了，当然也可能出现问题，注意看作者踩过的坑；

* 快速刷新：

  * 可以尝试使用google浏览器的访客功能来访问网址，应该不到一分钟就可以更新<username.github.io>和<自定义域名>之间的关联；

* 评论功能：

  * 因为我用的是giscus方式，因此就用giscus来做介绍；

  * 到[giscus](https://github.com/apps/giscus)将该app安装到自己的github.io仓库（当然你也可以不用github.io仓库，但是会影响到后续操作，这里只介绍github.io方式）；

  * 打开github.io仓库的discussion功能，在项目的setting当中；

  * 然后一步一步的按照[giscus](https://github.com/apps/giscus)中【configuration】中提到的去做，需要选择的地方可以选择默认；

  * 完成上述操作，可以得到repid，categoryid等参数，用于后续关联网站使用；

  * 找到_config.yml文件中的 comments部分，将变量设置为上面生成的内容，active：后填写 giscus，没有引号，注意在配置剩余其他变量的时候，需要单引号包裹，即使是rep部分，注释使用的是<username>/<rep>，这里也是需要用单引号包裹，如：'CoderOldSix/CoderOldSix.github.io'；

  * 修改上述完成以后，利用git提交到远端库；

  * 等待github编译完成，然后用访客方式打开自己的域名；


