Vundle
=============================

These notes are based on the article at [ this page](www.digitalocean.com/community/tutorials/how-to-use-vundle-to-manage-vim-plugins-on-a-linux-vpse ~/.vimrc).

**Install and Configure**

```
git clone https://github.com/gmarik/vundle.git ~/.vim/bundle/vundle
vim ~/.vimrc

    set nocompatible
    filetype off
    set rtp+=~/.vim/bundle/vundle/
    call vundle#rc()
    
    " This is the Vundle package, 
    " which can be found on GitHub.
    " For GitHub repos, you specify 
    " plugins using the
    " 'user/repository' format
    Plugin 'gmarik/vundle'
    
    " We could also add repositories 
    " with a ".git" extension
    Plugin 'scrooloose/nerdtree.git'
    
    " To get plugins from Vim Scripts, 
    " you can reference the plugin
    " by name as it appears on the site
    Plugin 'Buffergator'
    
    " Now we can turn our filetype functionality back on
    filetype plugin indent on

```

**Install and Update Plugins**

```
vim 
:PluginInstall
:bdelete
PluginUpdate
PluginInstall!
```

**Manage Plugins with Vundle**

```
:Plugins
:PluginSearch! plugin_query
    
    " in .vimrc 

    set nocompatible
    filetype off
    set rtp+=~/.vim/bundle/vundle/
    call vundle#rc()
    
    Plugin 'gmarik/vundle'
    
    Plugin 'scrooloose/nerdtree.git'
    
    Plugin 'Buffergator'
    
    Plugin 'plugin_query'
    
    filetype plugin indent on

```

**Install Plugins**

```
:PluginInstall
```
