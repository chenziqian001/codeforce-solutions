import numpy as np

def check_inputs(prior, channel, eps=1e-9):
    prior = np.asarray(prior, dtype=float)
    channel = np.asarray(channel, dtype=float)
    prior = np.clip(prior, 0.0, None)
    prior = prior / prior.sum()
    return prior, channel

def map_decoder_rule(prior, channel):
    prior, channel = check_inputs(prior, channel)
    joint = prior[:, None] * channel
    return np.argmax(joint, axis=0)

def ml_decoder_rule(prior, channel):
    prior, channel = check_inputs(prior, channel)
    return np.argmax(channel, axis=0)

def average_error_probability(prior, channel, decision_rule):
    prior, channel = check_inputs(prior, channel)
    M, N = channel.shape
    decision_rule = np.asarray(decision_rule, dtype=int)
    decoded_eq_x = (np.arange(M)[:, None] == decision_rule[None, :]).astype(float)
    correct_prob = prior[:, None] * channel * decoded_eq_x
    return float(1.0 - correct_prob.sum())

def detailed_report(prior, channel):
    prior, channel = check_inputs(prior, channel)
    map_dec = map_decoder_rule(prior, channel)
    ml_dec = ml_decoder_rule(prior, channel)
    pe_map = average_error_probability(prior, channel, map_dec)
    pe_ml = average_error_probability(prior, channel, ml_dec)

    print("MAP决策:", map_dec)
    print("ML决策:", ml_dec)
    print("MAP平均错误概率:", pe_map)
    print("ML平均错误概率:", pe_ml)

    return {
        "map_decision": map_dec,
        "ml_decision": ml_dec,
        "pe_map": pe_map,
        "pe_ml": pe_ml
    }

def example_binary_bsc():
    p = 0.6
    flip = 0.1
    prior = np.array([p, 1-p])
    channel = np.array([[1-flip, flip],[flip, 1-flip]])
    return detailed_report(prior, channel)

def example_arbitrary():
    prior = np.array([0.5, 0.3, 0.2])
    channel = np.array([
        [0.6, 0.1, 0.2, 0.1],
        [0.1, 0.7, 0.1, 0.1],
        [0.2, 0.2, 0.5, 0.1]
    ])
    return detailed_report(prior, channel)

def main():
    example_binary_bsc()
    example_arbitrary()

if __name__ == "__main__":
    main()
