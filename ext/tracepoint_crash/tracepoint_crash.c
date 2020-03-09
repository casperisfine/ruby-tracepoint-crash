#include <ruby.h>
#include <ruby/debug.h>
#include <stdbool.h>

static VALUE tracepoint = Qnil;

static void 
gctracker_hook(VALUE tpval, void *data)
{
        // noop
}

static bool
create_tracepoint() 
{
  rb_event_flag_t events;
  events = RUBY_INTERNAL_EVENT_GC_EXIT;
  tracepoint = rb_tracepoint_new(0, events, gctracker_hook, NULL);
  if (NIL_P(tracepoint)) {
    return false;
  }
  rb_global_variable(&tracepoint);
  return true;
}

static VALUE
tracepoint_enable(VALUE klass)
{
  if (!NIL_P(tracepoint)) {
    return Qtrue;
  }

  if(!create_tracepoint()) {
    return Qfalse;
  }

  rb_tracepoint_enable(tracepoint);
  return Qtrue;
}

void
Init_tracepoint_crash()
{
  VALUE cRubyTracePointCrash = rb_const_get(rb_cObject, rb_intern("RubyTracePointCrash"));

  rb_define_module_function(cRubyTracePointCrash, "enable", tracepoint_enable, 0);
}
