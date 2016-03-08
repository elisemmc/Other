
call plug#begin('~/.vim/plugged')

Plug 'crusoexia/vim-monokai'

filetype plugin indent on
call plug#end()
" All plugins must be defined before this line

au VimEnter * !xmodmap -e 'clear Lock' -e 'keycode 0x42 = Escape'
au VimLeave * !xmodmap -e 'clear Lock' -e 'keycode 0x42 = Caps_Lock'

set tabstop=4
set shiftwidth=4
set expandtab
colorscheme monokai

if has("mac")
    set clipboard+=unnamed
else
    set clipboard+=unnamedplus
endif

if has('mouse')
    set mouse=a
endif
