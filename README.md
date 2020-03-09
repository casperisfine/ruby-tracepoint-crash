Ruby 2.7.0 crash on exit if there is an active RUBY_INTERNAL_EVENT_GC_EXIT tracepoint:

[BUG] object allocation during garbage collection phase
ruby 2.7.0p0 (2019-12-25 revision 647ee6f091) [x86_64-darwin19]

-- Crash Report log information --------------------------------------------
   See Crash Report log file under the one of following:                    
     * ~/Library/Logs/DiagnosticReports                                     
     * /Library/Logs/DiagnosticReports                                      
   for more details.                                                        
Don't forget to include the above Crash Report log file in bug reports.     

-- Control frame information -----------------------------------------------
c:0001 p:0001 s:0003 E:002690 (none) [FINISH]


-- C level backtrace information -------------------------------------------
/Users/byroot/.rubies/ruby-2.7.0/bin/ruby(rb_vm_bugreport+0x96) [0x10fa9f266]
/Users/byroot/.rubies/ruby-2.7.0/bin/ruby(rb_bug+0xcc) [0x10faabb86]
/Users/byroot/.rubies/ruby-2.7.0/bin/ruby(newobj_slowpath+0x99c) [0x10f8f939c]
/Users/byroot/.rubies/ruby-2.7.0/bin/ruby(newobj_slowpath_wb_protected+0x14) [0x10f8f89d4]
/Users/byroot/.rubies/ruby-2.7.0/bin/ruby(rb_str_buf_new+0x1e) [0x10fa151be]
/Users/byroot/.rubies/ruby-2.7.0/bin/ruby(rb_enc_vsprintf+0x48) [0x10fa03178]
/Users/byroot/.rubies/ruby-2.7.0/bin/ruby(rb_vraise+0x14) [0x10f8d4d84]
/Users/byroot/.rubies/ruby-2.7.0/bin/ruby(rb_raise+0x7b) [0x10f8d052b]
/Users/byroot/.rubies/ruby-2.7.0/bin/ruby(rb_check_typeddata+0xf3) [0x10f8d19a3]
/Users/byroot/.rubies/ruby-2.7.0/bin/ruby(tp_call_trace+0x2a) [0x10faa1aaa]
/Users/byroot/.rubies/ruby-2.7.0/bin/ruby(rb_exec_event_hooks+0x163) [0x10faa0ab3]
/Users/byroot/.rubies/ruby-2.7.0/bin/ruby(rb_objspace_call_finalizer+0x8b7) [0x10f8eded7]
/Users/byroot/.rubies/ruby-2.7.0/bin/ruby(rb_ec_cleanup+0x2de) [0x10f8dc35e]
/Users/byroot/.rubies/ruby-2.7.0/bin/ruby(ruby_run_node+0x5f) [0x10f8dc4ff]
/Users/byroot/.rubies/ruby-2.7.0/bin/ruby(main+0x5d) [0x10f833d0d]

It also crash in other circumstances, but I'm not able to reproduce them as easily.

Older rubies are not affected.