           b1 	       	                         �d   g�&�3�                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              ����� �4,LD,$,$`X��������H@�����x���������
�
���	�	������@
8
d\��ld�
�
��`	X	��TL��d\����<4��D<|	t	�x$���� �
��@	8	��$������D< phxp�LD������ 		��|t�	�	D<��\T( tlh`

( ��0( ld��p
h
�	�	��TL����                   #     decl.hsrc    #    	 mu.lsrc  #    	 mu.hsrc  #    	 mu.ysrc  #     rule.Csrc    #     parse.Csrc   #     cpp_sym.hsrc     #     expr.hsrc    #     cpp_sym_decl.Csrc    #     lextable.hsrc    #     lex.yy.csrc  #     expr.Csrc    #     lextable.Csrc    #     y.tab.csrc   #     cpp_code.Csrc    #     rule.hsrc    #     cpp_code_as.Csrc     #     symtab.Csrc  #     no_code.Csrc     #     Makefilesrc  #     error.Csrc   #    	 mu.Csrc  #     y.tab.hsrc   #     stmt.Csrc    #     decl.Csrc    #     stmt.hsrc    #     cpp_sym_aux.Csrc     #     cpp_sym.Csrc     #     mu_verifier.Cinclude     #     mu_hash.hinclude     #     mu_io.Cinclude   #     mu_state.hinclude    #     mu_verifier.hinclude     #     mu_sym.hinclude  #    / mu_verifier.Cinclude/murphi.parallel.nothread    #    + mu_hash.hinclude/murphi.parallel.nothread    #    ) mu_io.Cinclude/murphi.parallel.nothread  #    , mu_state.hinclude/murphi.parallel.nothread   #    / mu_verifier.hinclude/murphi.parallel.nothread    #    * mu_sym.hinclude/murphi.parallel.nothread     #    + mu_util.Cinclude/murphi.parallel.nothread    #    . mu_statecl.hinclude/murphi.parallel.nothread     #    ) mu_io.hinclude/murphi.parallel.nothread  #    , mu_state.Cinclude/murphi.parallel.nothread   #    + mu_util.hinclude/murphi.parallel.nothread    #    + mu_hash.Cinclude/murphi.parallel.nothread    #    * mu_par.hinclude/murphi.parallel.nothread     #    - mu_system.Cinclude/murphi.parallel.nothread  #    * mu_par.Cinclude/murphi.parallel.nothread     #    / mu_util_dep.hinclude/murphi.parallel.nothread    #    - mu_system.hinclude/murphi.parallel.nothread  #    * mu_sym.Cinclude/murphi.parallel.nothread     #     mu_util.Cinclude     #     mu_statecl.hinclude  #     mu_io.hinclude   #     mu_state.Cinclude    #     mu_util.hinclude     #     mu_hash.Cinclude     #    $ splitFile.hinclude/murphi.parallel   #    & mu_verifier.Cinclude/murphi.parallel     #    " mu_hash.hinclude/murphi.parallel     #    $ splitFile.Cinclude/murphi.parallel   #    ' mu_buffqueue.Cinclude/murphi.parallel    #      mu_io.Cinclude/murphi.parallel   #    # mu_state.hinclude/murphi.parallel    #    & mu_verifier.hinclude/murphi.parallel     #    ! mu_log.hinclude/murphi.parallel  #    " mu_util.Cinclude/murphi.parallel     #    ' mu_buffqueue.hinclude/murphi.parallel    #    % mu_mutexes.Cinclude/murphi.parallel  #    % mu_statecl.hinclude/murphi.parallel  #      mu_io.hinclude/murphi.parallel   #    # mu_state.Cinclude/murphi.parallel    #    " mu_util.hinclude/murphi.parallel     #    " mu_hash.Cinclude/murphi.parallel     #    & mu_parallel.hinclude/murphi.parallel     #    & mu_parallel.Cinclude/murphi.parallel     #    $ mu_system.Cinclude/murphi.parallel   #    $ mu_system.hinclude/murphi.parallel   #    % mu_mutexes.hinclude/murphi.parallel  #     mu_system.Cinclude   #     mu_util_dep.hinclude     #     mu_system.hinclude   #     mu_io.Cinclude/murphi.cache  #      mu_state.hinclude/murphi.cache   #    " mu_statecl.hinclude/murphi.cache     #     mu_io.hinclude/murphi.cache  #      mu_state.Cinclude/murphi.cache   #     mu_util.hinclude/murphi.cache    #    ! mu_system.Cinclude/murphi.cache  #    ! mu_system.hinclude/murphi.ca,     �]�	mu_state.hinclude/murphi.parallel.nothread                            v �������0(TL����ph��������tlXP80 �����������ldPH<4(  �����xpH@������ldD<������tl@8�
�
�
�
|
t
D
<


�	�	�	�	�	�	`	X	(	 		 	���� any later version.
# 
# Source-Navigator is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.
# 
# You should have received a copy of the GNU General Public License along
# with Source-Navigator; see the file COPYING.  If not, write to
# the Free Software Foundation, 59 Temple Place - Suite 330, Boston,
# MA 02111-1307, USA.
# 
################################################
##
## Window for project symbols
##
################################################
itcl_class SymBr& {
    inherit sourcenav::Window

    constructor {{config ""}} {
        global sn_options

        set topw $itk_component(hull)
        set symbr $itk_component(hull).symbr

        on_close "$itk_component(hull) windows_close dummy"
        #don't close window by hitting Escape
      #  ${this} bind_tk <Escape> {;}

        withdraw

        if {${x} != ""} {
            $this configure -geometry [expr {int(${width})}]x[expr\
              {int(${height})}]+${x}+${y}
        } else {
            set height [expr {int([winfo screenheight .] *
                ($sn_options(def,window-size)*0.01))}]
            set width [expr {int([winfo screenwidth .] / 3)}]
            if {${width} < 300} {
                set width 300
            } elseif {${width} > 450} {
                set width 450
            }
            $this configure -geometry ${width}x${height}
        }

        set Toolbar $itk_component(hull).exp
        set Statusbar $itk_component(hull).msg

        AddMenu
        AddToolbar
  #   A HOWTO.Eddy_Murphi.txtdoc pon # ull Makefileex/toy o # n_o Makefileex/sci o #     Makefileex/dash  #     Makefileex/others    #     Makefileex/multiset+sym  # -me Makefileex/mux h # men Makefileex/sym o #  "$ Makefileex/secur     #    # mu_state.hinclude/murphi.parallel    #      mu_state.hinclude/murphi.cache   #     mu_state.hinclude    #    , mu_state.Cinclude/murphi.parallel.nothread   #    # mu_state.Cinclude/murphi.parallel    #      mu_state.Cinclude/murphi.cache   #     mu_state.Cinclude    #    & mu_parallel.hinclude/murphi.parallel     #    & mu_parallel.Cinclude/murphi.parallel     #    * mu_par.hinclude/murphi.parallel.nothread     #    * mu_par.Cinclude/murphi.parallel.nothread     #    % mu_mutexes.hinclude/murphi.parallel  #    % mu_mutexes.Cinclude/murphi.parallel  #    ! mu_log.hinclude/murphi.parallel  #    ) mu_io.hinclude/murphi.parallel.nothread  #      mu_io.hinclude/murphi.parallel   #     mu_io.hinclude/murphi.cache  #     mu_io.hinclude   #    ) mu_io.Cinclude/murphi.parallel.nothread  #      mu_io.Cinclude/murphi.parallel   #     mu_io.Cinclude/murphi.cache  #     mu_io.Cinclude   #    + mu_hash.hinclude/murphi.parallel.nothread    #    " mu_hash.hinclude/murphi.parallel     #     mu_hash.hinclude     #    + mu_hash.Cinclude/murphi.parallel.nothread    #    " mu_hash.Cinclude/murphi.parallel     #     mu_hash.Cinclude     #    ' mu_buffqueue.hinclude/murphi.parallel    #    ' mu_buffqueue.Cinclude/murphi.parallel    #    	 mu.ysrc  #    	 mu.lsrc  #    	 mu.hsrc  #    	 mu.Csrc  #     lextable.hsrc    #     lextable.Csrc    #     lex.yy.csrc  #     expr.hsrc    #     expr.Csrc    #     error.Csrc   #     decl.hsrc    #     decl.Csrc    #     cpp_sym_decl.Csrc    #     cpp_sym_aux.Csrc     #     cpp_sym.hsrc     #     cpp_sym.Csrc     #     cpp_code_as.Csrc     #     cpp_code.Csrc    #     Makefilesrc  #     HOWTO.Eddy_Murphi.txt.                   Z ������xPH������ldLD ������ld<4�����|t\T0( �����h`D<�
�
�
�
|
t
@
8
$



���	�	�	�	�	�	|	t	d	\	L	D	4	,	��			�] -expand y\
          -fill both -side left
        pack ${Statusbar} -side bottom -fill x
    }

    method handle_select {{scope ""} {sym ""} {cls ""} {file ""} {from ""}\
      {type ""} {prm ""} {to ""} {always 1}} {
        if {${scope} == "cl"} {
            set cls ${sym}
        }
        if {${cls} != "" && ${scope} != "cov"} {
            set class_state normal
        } else {
            set class_state disabled
        }
        if {${file} != ""} {
            set inc_state [tool_Exists incbr]
        } else {
            set inc_state disabled
        }
        set xref_state [tool_Exists xref]
        if {${sym} == "" && ${xref_state} == "normal"} {
            set xref_state disabled
        }
        ${Toolbar}.tree config -state ${class_state}
        ${Toolbar}.class config -state ${class_state}
        ${Toolbar}.inc config -state ${inc_state}
        ${Toolbar}.xref config -state ${xref_state}
    }

    method run_tool {tool {scope ""} {sym ""} {cls ""} {file ""} {from ""}\
      {type ""} {prm ""} {to ""} {always 1}} {
        switch -- ${tool} {
            "inc" {
                    sn_include ${file}
                }
            "xref" {
                    if {${from} == ""} {
                        set from -1
                    }
                    if {${to} == ""} {
                        set to -1
                    }
                    if {${cls} != ""} {
                        set sym "${cls}\:\:${sym}(${scope})"
                    } else {
                        set sym ${sym}(${scope})
                    }
                    sn_xref both [string trim ${sym}] ${type} ${file} ${from}\
                      ${to} ${prm}
                }
            "class" {
                    #go direct to the member if something given
                    sn_classbrowser "" [list ${scope} ${sym} ${cls} ${file}\
                      ${from} ${type} ${prm} ${to}]
                }
            "ctree" {
                    if {${scope} == "cl"} {
                       #  cl real_trace.txtex/sci     #     util.Csrc  s #     y.tab.hsrc   #     y.tab.csrc   #     symtab.Csrc  #     stmt.hsrc    #     stmt.Csrc    #    $ splitFile.hinclude/murphi.parallel   #    $ splitFile.Cinclude/murphi.parallel   #     rule.hsrc    #     rule.Csrc    #     parse.Csrc   #     no_code.Csrc     #    / mu_verifier.hinclude/murphi.parallel.nothread    #    & mu_verifier.hinclude/murphi.parallel     #     mu_verifier.hinclude     #    / mu_verifier.Cinclude/murphi.parallel.nothread    #    & mu_verifier.Cinclude/murphi.parallel     #     mu_verifier.Cinclude     #    / mu_util_dep.hinclude/murphi.parallel.nothread    #     mu_util_dep.hinclude     #    + mu_util.hinclude/murphi.parallel.nothread    #    " mu_util.hinclude/murphi.parallel     #     mu_util.hinclude/murphi.cache    #     mu_util.hinclude     #    + mu_util.Cinclude/murphi.parallel.nothread    #    " mu_util.Cinclude/murphi.parallel     #     mu_util.Cinclude     #    - mu_system.hinclude/murphi.parallel.nothread  #    $ mu_system.hinclude/murphi.parallel   #    ! mu_system.hinclude/murphi.cache  #     mu_system.hinclude   #    - mu_system.Cinclude/murphi.parallel.nothread  #    $ mu_system.Cinclude/murphi.parallel   #    ! mu_system.Cinclude/murphi.cache  #     mu_system.Cinclude   #    * mu_sym.hinclude/murphi.parallel.nothread     #     mu_sym.hinclude  #    * mu_sym.Cinclude/murphi.parallel.nothread     #     mu_sym.Cinclude  #    . mu_statecl.hinclude/murphi.parallel.nothread     #    % mu_statecl.hinclude/murphi.parallel  #    " mu_statecl.hinclude/murphi.cache     #     mu_statecl.hinclude  #    , mu_state.hinclude/murphi.parallel.nothread  