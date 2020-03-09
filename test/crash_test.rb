require 'test_helper'

class CrashTest < Minitest::Test
  def test_crash
    RubyTracePointCrash.enable
  end
end