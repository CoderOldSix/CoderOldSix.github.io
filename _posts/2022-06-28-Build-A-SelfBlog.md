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
