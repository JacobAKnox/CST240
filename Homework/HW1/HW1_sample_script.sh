#!/bin/bash
cat > sample.txt << EOF
cat
dog
spider
anteater
EOF

cat sample.txt | sort > sorted_sample.txt
cat sorted_sample.txt
