import streamlit as st
from datetime import datetime

# Function to calculate the time elapsed
def time_elapsed(start_time):
    if start_time:
        return datetime.now() - start_time
    else:
        return "Not started"

# Ensure session state keys exist with initial values
if 'start_time_1' not in st.session_state:
    st.session_state['start_time_1'] = None
if 'start_time_2' not in st.session_state:
    st.session_state['start_time_2'] = None

# Layout for the timer application
st.title('Persistent Timers App')

# Timer 1
st.header('Timer 1')
if st.button('Start/Restart Timer 1'):
    st.session_state['start_time_1'] = datetime.now()
st.write('Time elapsed:', time_elapsed(st.session_state['start_time_1']))

# Divider
st.markdown('---')  # Just a separator for better visualization

# Timer 2
st.header('Timer 2')
if st.button('Start/Restart Timer 2'):
    st.session_state['start_time_2'] = datetime.now()
st.write('Time elapsed:', time_elapsed(st.session_state['start_time_2']))

# This command asks Streamlit to rerun from the top, so the page gets refreshed and the timers update.
st.experimental_rerun()
