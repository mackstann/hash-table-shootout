import os, subprocess, signal, time

programs = [
    'glib_hash_table',
    'stl_unordered_map',
    'boost_unordered_map',
    'google_sparse_hash_map',
    'google_dense_hash_map',
    'qt_qhash',
    'python_dict',
]

minkeys = 1000*1000
maxkeys = 21*1000*1000
interval = 10000000

# for the final run, use this:
#maxkeys = 40*1000*1000
#interval = 500000
# and use nice/ionice
# and shut down to the console

outfile = open('output', 'w')

for benchtype in ('sequential', 'random'):
    nkeys = minkeys
    while nkeys <= maxkeys:
        for program in programs:
            fastest_attempt = 1000000
            fastest_attempt_data = ''

            for attempt in range(3): # best of 3
                before = time.time()
                proc = subprocess.Popen(['./'+program, str(nkeys), benchtype], stdout=subprocess.PIPE)

                # wait for the program to fill up memory and spit out its "ready" message
                proc.stdout.read(1)
                after = time.time()

                ps_proc = subprocess.Popen(['ps up %d | tail -n1' % proc.pid], shell=True, stdout=subprocess.PIPE)
                nbytes = int(ps_proc.stdout.read().split()[4]) * 1024
                os.kill(proc.pid, signal.SIGTERM)

                if nbytes: # otherwise it crashed
                    line = ','.join(map(str, [benchtype, nkeys, program, nbytes, after-before]))

                    if after-before < fastest_attempt:
                        fastest_attempt = after-before
                        fastest_attempt_data = line

            if fastest_attempt != 1000000:
                print >> outfile, fastest_attempt_data
                print fastest_attempt_data

        nkeys += interval
