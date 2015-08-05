#!/bin/bash
set -o nounset

if [[ $# -ne 1 ]]; then
  exit 1;
fi
if [[ $1 = "pdf" ]]; then
  echo "$0 $1 pdf";
elif [[ $1 = "html" ]]; then
  echo "$0 $1 html";
fi
